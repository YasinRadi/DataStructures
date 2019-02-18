using System;
using System.Text;

/// <summary> 
/// HashTable / HashMap implementation class.
/// </summary>
public class HashTable
{
    // HashTable max size
    public static readonly int TABLE_SIZE = 128;

    // Elements storage
    HashNode[] elements;

    // Current map size
    private int len;

    /// <summary>
    /// HashNode class implementation.
    /// </summary>
    private class HashNode
    {
        // HashNode key
        public int key;

        // HashNode value
        public int value;

        public HashNode(int k, int v) {
            this.key = k;
            this.value = v;
        }
    }

    public HashTable() {
        this.len = 0;
        this.elements = new HashNode[TABLE_SIZE];
    }

    /// <summary> 
    /// Hashing function.
    /// </summary>
    /// <param name="k">Key to hash.</param>
    /// <returns>The hashed key.</returns>
    public int HashFunc(int k) {
        return k % TABLE_SIZE;
    }

    /// <summary>
    /// Inserts a new node into the map.
    /// </summary>
    /// <param name="k">Key of the node.</param>
    /// <param name="v">Value of the param.</param>
    public void Insert(int k, int v) {
        int hash = HashFunc(k);
        while (elements[hash] != null && elements[hash].key != k)
            hash = HashFunc(++hash);

        len++;
        elements[hash] = new HashNode(k, v);
    }

    /// <summary>
    /// Retrieve element from map related to given key.
    /// </summary>
    /// <param name="k">Key of element to retrieve.</param>
    /// <returns>Value related to given key.</returns>
    public int Get(int k) {
        int hash = HashFunc(k);
        while (elements[hash] != null && elements[hash].key != k)
            hash = HashFunc(++hash);

        return elements[hash] != null ? elements[hash].value : -1;
    }

    /// <summary> 
    /// Checks if given key is in map.
    /// </summary>
    /// <param name="k">Key to check.</param>
    /// <returns>true if the key is in map, false otherwise.</returns>
    public bool Contains(int k) {
        return Get(k) != -1;
    }

    /// <summary>
    /// Display map< K, V > content.
    /// </summary>
    public void Display() {
        StringBuilder sb = new StringBuilder();
        foreach (HashNode n in elements) {
            if (n != null) {
                sb.Append("{K: ").Append(n.key);
                sb.Append(" V : ").Append(n.value);
                sb.Append("}\n");
            }
        }
        Console.WriteLine(sb.ToString());
    }

    /// <summary>
    /// Remove a < K, V > given a K from map.
    /// </summary>
    /// <param name="k">Key to remove from map.</param>
    public void Remove(int k) {
        int hash = HashFunc(k);
        while (elements[hash] != null) {
            if (elements[hash].key != k) {
                hash = HashFunc(++hash);
                continue;
            }

            break;
        }

        if (elements[hash] == null) return;

        len--;
        elements[hash] = null;
    }

    /// <summary>
    /// Size of the map.
    /// </summary>
    public int Size() {
        return len;
    }
}