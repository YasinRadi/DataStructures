
ALPHABET_SIZE = 26

class TrieNode:
    """ Trie node implementation class. """

    def __init__(self):

        # True if node represents end of word
        self.isEndOfWord = False
        self.children = [None for _ in range(ALPHABET_SIZE)]

class Trie:
    """ Trie implementation class. """

    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, key):
        crawl = self.root
        
        for i in range(len(key)):
            idx = ord(key[i]) - ord('a')
            # If current char is not present
            if crawl.children[idx] is None:
                crawl.children[idx] = TrieNode()
            crawl = crawl.children[idx]
        
        crawl.isEndOfWord = True
    
    def search(self, key):
        crawl = self.root

        for i in range(len(key)):
            idx = ord(key[i]) - ord('a')
            if crawl.children[idx] is None: 
                return False
            
            crawl = crawl.children[idx]
        
        return crawl is not None and crawl.isEndOfWord
            

    def isEmpty(self, node):
        for i in range(ALPHABET_SIZE):
            if node.children[i]: return False
        return True
    
    def remove(self, node, key, depth=0):
        # If tree is empty
        if not node: return None
        
        # If last character of key is being processed
        if depth == len(key):

            # This node is no more end of word
            # after removal of given key
            if node.isEndOfWord: node.isEndOfWord = False
            
            if self.isEmpty(node):
                del node
                node = None
            
            return node
        
        # If not last char, recur for the child
        # obtained using ascii value
        idx = ord(key[depth]) - ord('a')
        node.children[idx] = self.remove(node, key, depth + 1)

        # If root does not have any children (its only child got deleted)
        # and it's not end of another word
        if self.isEmpty(node) and not node.isEndOfWord:
            del node
            node = None

        return node

    def display(self, string, node, level=0):
        # If node is end of word, it indicates end of string
        # so it might be displayed
        if node.isEndOfWord:
            print(''.join(string))
            string = ['' for _ in range(len(string))]

        
        for i in range(ALPHABET_SIZE):
            # If non null child is found
            # add parent key to str and
            # call the display function
            # recursively for child node
            if node.children[i]:
                string[level] = chr(i + ord('a'))
                self.display(string, node.children[i], level + 1)


if __name__ == '__main__':
    keys = [
        "the", 
        "a", 
        "there", 
        "answer",
        "any",
        "by",
        "bye",
        "their",
        "hero",
        "heroplane"
    ]

    keys2 = [
        'banning', 'banned', 'banana', 'bad', 'cooking', 'cought', 'count'
    ]

    trie = Trie()

    # Build Trie
    #for s in keys: trie.insert(s)
    for s in keys: trie.insert(s)

    # Search for different keys
    r = 'Yes' if trie.search('the') else 'No'
    print('Is "the" in trie?: {0}'.format(r))

    r = 'Yes' if trie.search('these') else 'No'
    print('Is "these" in trie?: {0}'.format(r))

    r = 'Yes' if trie.search('heroplane') else 'No'
    print('Is "heroplane" in trie?: {0}'.format(r))

    r = 'Yes' if trie.search('bye') else 'No'
    print('Is "bye" in trie?: {0}'.format(r))

    print('Remove "heroplane"')
    trie.remove(trie.root, 'heroplane')

    r = 'Yes' if trie.search('heroplane') else 'No'
    print('Is "heroplane" in trie?: {0}'.format(r))



