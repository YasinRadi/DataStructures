
/**
 * Trie Implementation class.
 * @author Yasin Radi
 */
public class Trie {

    /**
     * Trie node implementation.
     */
    private class TrieNode {

        static final int ALPHABET_SIZE = 26;
    
        public TrieNode[] children;
    
        public boolean isEndOfWord;
    
        public TrieNode() {
            this.isEndOfWord = false;
            this.children = new TrieNode[ALPHABET_SIZE];
            for(int i = 0; i < ALPHABET_SIZE; i++)
                this.children[i] = null;
        };
    };

    private TrieNode root;

    public Trie() {
        this.root = new TrieNode();
    };

    /**
     * Inserts a new key into the {@link TrieNode}.
     * @param key   String
     */
    public void insert(String key) {
        TrieNode crawl = this.root;
        
        for(int i = 0; i < key.length(); i++) {
            int idx = key.charAt(i) - 'a';
            if(crawl.children[idx] == null)
                crawl.children[idx] = new TrieNode();
            
            crawl = crawl.children[idx];
        };

        crawl.isEndOfWord = true;
    };

    /**
     * Searches whether or not a given key
     * exists in the {@link TrieNode}
     * @param key   String
     * @return      boolean
     */
    public boolean search(String key) {
        TrieNode crawl = this.root;

        for(int i = 0; i < key.length(); i++) {
            int idx = key.charAt(i) - 'a';
            if(crawl.children[idx] == null)
                return false;
            
            crawl = crawl.children[idx];
        };

        return crawl != null && crawl.isEndOfWord;
    };

    /**
     * Checks if a given {@link TrieNode} is empty.
     * @param node  TrieNode
     * @return      boolean
     */
    public boolean isEmpty(TrieNode node) {
        for(int i = 0; i < TrieNode.ALPHABET_SIZE; i++)
            if(node.children[i] != null) return false;
        return true;
    };

    /**
     * Removes a given key from the {@link TrieNode}
     * @param node   TrieNode
     * @param key    String
     * @param depth  int
     * @return       TrieNode
     */
    public TrieNode remove(TrieNode node, String key, int depth) {
        // Tree is empty
        if(node == null) return null;

        // If last character is being processed
        if(depth == key.length()) {
            
            // This node is no more end of word after
            // removing given key
            if(node.isEndOfWord) node.isEndOfWord = false;

            // If given is not prefix of any other word
            if(isEmpty(node)) node = null;
            
            return node;
        };

        // If not last char, recur for the child 
        // obtained using ASCII value
        int idx = key.charAt(depth) - 'a';
        node.children[idx] = remove(node, key, depth + 1);

        // If root does not have any children (it's only child got
        // deleted) and it's not end of word
        if(isEmpty(node) && node.isEndOfWord == false) node = null;

        return node;
    };

    public static void main(String[] args) {
        String[] keys = {
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
        };

        Trie trie = new Trie();

        // Build Trie
        for(String k : keys) trie.insert(k);

        System.out.println("Is 'the' in trie?: " + 
        trie.search("the"));

        System.out.println("Is 'these' in trie?: " + 
        trie.search("these"));

        System.out.println("Is 'heroplane' in trie?: " + 
        trie.search("heroplane"));

        System.out.println("Is 'bye' in trie?: " + 
        trie.search("bye"));

        System.out.println("Remove 'heroplane'");
        trie.remove(trie.root, "heroplane", 0);

        System.out.println("Is 'heroplane' in trie?: " + 
        trie.search("heroplane"));
    };
};