#include <iostream>
#include <string>

const int ALPHABET_SIZE = 26;

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];

    // It's true of the node represents
    // the end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULL)
struct TrieNode* getNode();

/* 
    If not present, inserts key into trie
    If the key is prefix of trie node, just
    marks leaf node.
*/
void insert(struct TrieNode*, std::string);


// Returns true if key present in trie, 
// false otherwise
bool search(struct TrieNode*, std::string);


// Returns true if root has no children
// false otherwise
bool isEmpty(struct TrieNode*);


// Recursive function to delete a key from a given Trie
struct TrieNode* remove(struct TrieNode*, std::string, int = 0);


// Function to display Trie content
void display(struct TrieNode*, char*, int);



struct TrieNode* getNode() {
    struct TrieNode* pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for(int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    
    return pNode;
};

void insert(struct TrieNode* root, std::string key) {
    struct TrieNode* pCrawl = root;

    for(int i = 0; i < key.length(); i++) {
        int idx = key[i] - 'a';
        if(!pCrawl->children[idx])
            pCrawl->children[idx] = getNode();
        
        pCrawl = pCrawl->children[idx];
    }

    pCrawl->isEndOfWord = true;
};

bool search(struct TrieNode* root, std::string key) {
    struct TrieNode* pCrawl = root;

    for(int i = 0; i < key.length(); i++) {
        int idx = key[i] - 'a';
        if(!pCrawl->children[idx])
            return false;
        
        pCrawl = pCrawl->children[idx];
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord);
};

bool isEmpty(struct TrieNode* root) {
    for(int i = 0; i < ALPHABET_SIZE; i++) 
        if(root->children[i]) return false;
    return true;
};

struct TrieNode* remove(struct TrieNode* root, std::string key, int depth) {
    // If tree is empty
    if(!root) return NULL;

    // If last character of key is being processed
    if(depth == key.length()) {

        // This node is no more end of word after removal
        // of given key
        if(root->isEndOfWord) root->isEndOfWord = false;

        // If given is not prefix of any other word
        if(isEmpty(root)) {
            delete root;
            root = NULL;
        }

        return root;
    }

    // If not last character, recur for the child
    // obtained using ASCII value
    int idx = key[depth] - 'a';
    root->children[idx] = remove(root->children[idx], key, depth + 1);

    // If root does not have any children (its only child got deleted)
    // and it's not end of another word.
    if(isEmpty(root) && root->isEndOfWord == false) {
        delete root;
        root = NULL;
    }

    return root;
};

void display(struct TrieNode* root, char* str, int level) {
    // If node is endOfWord, it indicates end of string, so 
    // it may be displayed
    if(root->isEndOfWord) {
        str[level] = '\0';
        std::cout << str << "\n";
    }

    for(int i = 0; i < ALPHABET_SIZE; i++) {
        /* 
            If non NULL child is found
            add parent key to str and
            call the display function recursively
            for child node.
        */
        if(root->children[i]) {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
};