from collections import defaultdict

class TrieNode:
    """ Trie node implementation class. """

    def __init__(self):
        self.timesUsed = 0
        self.isEndOfWord = False
        self.children = defaultdict(TrieNode)

class Trie:
    """ Trie implementation class. """

    def __init__(self):
        self.root = TrieNode()

    def insert(self, key: str):
        node = self.root
        
        for c in key:    
            node = node.children[c]
            node.timesUsed += 1
        
        node.isEndOfWord = True
    
    def search(self, key: str):
        node = self.root
        for c in key:
            if c not in node.children: 
                return None
            
            node = node.children[c]            
        return node
  
    