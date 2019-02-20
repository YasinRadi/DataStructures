using System;
using System.Linq;

/// <summary>
/// Trie implementation class.
/// </summary>
public class Trie
{
    /// <summary>
    /// Trie node implementation class.
    /// </summary>
    internal class TrieNode
    {
        // Alphabet size being used
        internal const int ALPHABET_SIZE = 26;

        // Children of node
        internal TrieNode[] children;

        // If this node is end of word
        internal bool isEndOfWord;

        // Constructor
        internal TrieNode() {
            this.isEndOfWord = false;
            this.children = new TrieNode[ALPHABET_SIZE];
            for (int i = 0; i < ALPHABET_SIZE; i++)
                children[i] = null;
        }
    }

    // Root of trie
    private TrieNode root;

    // Constructor
    public Trie() {
        this.root = new TrieNode();
    }

    /// <summary>
    /// Inserts a new key into the Trie.
    /// </summary>
    /// <param name="key">Key to be inserted.</param>
    public void Insert(string key) {
        TrieNode crawler = root;

        for (int i = 0; i < key.Length; i++) {
            int idx = key[i] - 'a';
            if (crawler.children[idx] == null) {
                crawler.children[idx] = new TrieNode();
            }

            crawler = crawler.children[idx];
        }

        crawler.isEndOfWord = true;
    }

    /// <summary>
    /// Searches whether or not a given key exists
    /// in the Trie.
    /// </summary>
    /// <param name="key">Key to search for.</param>
    /// <returns>True if key in Trie. False otherwise.</returns>
    public bool Search(string key) {
        TrieNode crawler = root;

        for (int i = 0; i < key.Length; i++) {
            int idx = key[i] - 'a';
            if (crawler.children[idx] == null) {
                return false;
            }

            crawler = crawler.children[idx];
        }

        return crawler != null && crawler.isEndOfWord;
    }

    /// <summary>
    /// Checks if a given TrieNode is empty.
    /// </summary>
    /// <param name="node">Node to be checked.</param>
    /// <returns>True if is empty. False otherwise.</returns>
    private bool IsEmpty(ref TrieNode node) {
        return !node.children.Any(n => n != null);
    }

    /// <summary>
    /// Helper recursive function to remove a given key from Trie.
    /// </summary>
    /// <param name="node">Node, children whom, will be checked.</param>
    /// <param name="key">Key to remove.</param>
    /// <param name="depth">Recursive depth counter.</param>
    /// <returns>Returns the node that has been deleted.</returns>
    private TrieNode RemoveHelper(ref TrieNode node, ref String key, int depth) {
        // Tree empty
        if (node == null) return null;

        // If last char is being processed
        if (depth == key.Length) {
            // This node is no more end of word
            // remove given key
            if (node.isEndOfWord) node.isEndOfWord = false;

            // Given node is not prefix of any other word
            if (IsEmpty(ref node)) node = null;

            return node;
        }

        // If not last char, recur for the child
        // obtained using ASCII val
        int idx = key[depth] - 'a';
        node.children[idx] = RemoveHelper(ref node, ref key, depth + 1);

        // If root does not have any children (its only child got deleted)
        // ant it's not end of word
        if (IsEmpty(ref node) && !node.isEndOfWord) node = null;

        return node;
    }

    /// <summary>
    /// Removes a given key from the Trie.
    /// </summary>
    /// <param name="key"></param>
    public void Remove(string key) {
        RemoveHelper(ref root, ref key, 0);
    }
}