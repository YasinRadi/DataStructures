
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
            # Get 0-idx position in alphabet
            idx = ord(key[i]) - ord('a')
            # If current char is not present
            if crawl.children[idx] is None:
                crawl.children[idx] = TrieNode()
            crawl = crawl.children[idx]
        
        crawl.isEndOfWord = True
    
    def startsPrefix(self, prefix):
        crawl = self.root
        for c in prefix:
            idx = ord(c) - ord('a')
            if crawl.children[idx] is None: 
                return None
            
            crawl = crawl.children[idx]            
        return crawl

    def search(self, key):
        node = self.startsPrefix(key)        
        return node is not None and node.isEndOfWord
            
    def startsWith(self, prefix):
        node = self.startsPrefix(prefix)
        return node is not None

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
    trie = Trie()

    trie.insert('app')
    print(f"Is app in trie?: {trie.search('app')}")
    print(f'Start with app: {trie.startsWith("ap")}')
    