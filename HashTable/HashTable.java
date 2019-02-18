
/**
 * HashTable / HashMap implementation class.
 * @author Yasin Radi
 */
public class HashTable {

    // HashTable max size
    final static int TABLE_SIZE = 128;

    // Elements storage
    private HashNode[] elements;

    // Current map size
    private int size_;

    /** HashNode class implementation. */
    private class HashNode {

        // HashNode key
        private int key;

        // HashNode value
        private int value;

        private HashNode(int k, int v) {
            this.key = k;
            this.value = v;
        };
    };

    public HashTable() {
        this.size_ = 0;
        this.elements = new HashNode[TABLE_SIZE];
    };

    /** Hash function. */
    private int hashFunc(int k) {
        return k % TABLE_SIZE;
    };

    /**
     * Insert a new node into the map.
     * @param k int
     * @param v int
     */
    public void insert(int k, int v) {
        int hash = hashFunc(k);
        while (this.elements[hash] != null && this.elements[hash].key != k) {
            hash = hashFunc(++hash);
        }

        this.size_++;
        this.elements[hash] = new HashNode(k, v);
    };

    /**
     * Retrieve from map the element related to the given key.
     * @param k int
     * @return  int
     */
    public int get(int k) {
        int hash = hashFunc(k);
        while (this.elements[hash] != null && this.elements[hash].key != k) {
            hash = hashFunc(++hash);
        }

        return this.elements[hash] != null ? this.elements[hash].value : -1;
    };

    /**
     * Check if given key is in map.
     * @param k int 
     * @return  boolean
     */
    public boolean contains(int k) {
        return get(k) != -1;
    };

    /** Display map<K, V> content. */
    public void display() {
        StringBuilder sb = new StringBuilder();
        for (HashNode n : this.elements) {
            if (n != null) {
                sb.append("{K: ").append(n.key);
                sb.append(" V : ").append(n.value);
                sb.append("}\n");
            }
        }
        System.out.println(sb.toString());
    };

    /**
     * Remove a <K, V> given a K from map.
     * @param k int
    */
    public void remove(int k) {
        int hash = hashFunc(k);
        while (this.elements[hash] != null) {
            if (this.elements[hash].key != k) {
                hash = hashFunc(++hash);
                continue;
            }

            break;
        }

        if (this.elements[hash] == null) {
            return;
        }
        
        this.size_--;
        this.elements[hash] = null;
    };

    /**
     * Size of map.
     * @return  int
     */
    public int size() {
        return this.size_;
    };
};