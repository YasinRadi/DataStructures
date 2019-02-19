/**
 * LinkedList implementation for data type <T>.
 * @author Yasin Radi
 */
public class LinkedList<T> {

    /**
     * Node class holding T data type implementation.
     * @param <T>   Type of the data
     */
    private class Node {
        // Data held by the node.
        public T data;

        // Pointer to the next node in the list.
        public Node next;

        // Node constructor
        public Node() {
            this.data = null;
            this.next = null;
        };

        public Node(T v) {
            this.data = v;
            this.next = null;
        };

        public Node(T v, Node next) {
            this.data = v;
            this.next = next;
        };
    };

    // Head node.
    private Node head;

    // Tail node.
    private Node tail;

    // Length list atrribute.
    private int length;

    public LinkedList() {
        this.length = 0;
        this.head = null;
        this.tail = null;
    };

    /**
     * Checks if the given index idx is in the list's bounds.
     * @param idx   int
     * @return      boolean
     */
    private boolean checkIndexBounds(int idx) {
        return (idx >= 0) && (idx < this.length);
    };

    /**
     * Adds a given node to the list.
     * @param node  Node
     */
    public void add(Node node) {
        if (this.head == null) {
            this.head = node;
            this.tail = node;
        } else {
            this.tail.next = node;
            this.tail = node;
        }

        this.length++;
    };

    /**
     * Adds a node to the list created
     * using a given <T> value.
     * @param v <T>
     */
    public void add(T v) {
        add(new Node(v));
    };

    /**
     * Displays the content of all nodes.
     */
    public void displayNodes() {
        Node node = this.head;
        StringBuilder sb = new StringBuilder();
        while (node != null) {
            sb.append(node.data).append(" ");
            node = node.next;
        };

        System.out.println(sb.toString());
    };

    /**
     * Gets the node before the given index.
     * @param idx   int
     * @return      Node
     */
    public Node getNodeBeforeIndex(int idx) {
        if(!checkIndexBounds(idx)) {
            return null;
        }

        Node curr = this.head;
        Node pre = new Node();
        for (int i = 0; i < idx; i++) {
            pre = curr;
            curr = curr.next;
        };

        return pre;
    };

    /**
     * Adds a node at the beginning of the list 
     * created from a given <T> value.
     * @param v <T>
     */
    public void addAtStart(T v) {
        if (this.head == null) {
            add(v);
            return;
        };

        Node node = new Node(v, this.head);
        this.head = node;
        this.length++;
    };

    /**
     * Adds a given Node at the beginning of the list.
     * @param node  Node
     */
    public void addAtStart(Node node) {
        if(this.head == null) {
            add(node);
            return;
        };

        node.next = this.head;
        this.head = node;
        this.length++;
    };

    /**
     * Adds a given Node at the given index idx.
     * @param idx   int
     * @param node  Node
     */
    public void addAtIndex(int idx, Node node) {
        if (!checkIndexBounds(idx)) {
            return;
        }

        Node pre = getNodeBeforeIndex(idx);
        Node curr = pre.next;
        pre.next = node;
        node.next = curr;
        this.length++;
    };

    /**
     * Adds a given Node created from <T> value v
     * at the given index idx.
     * @param idx   int
     * @param v     <T>
     */
    public void addAtIndex(int idx, T v) {
        addAtIndex(idx, new Node(v));
    };

    /**
     * Pops out the first element of the list.
     */
    public void popFirst() {
        this.head = this.head.next;
        this.length--;
    };

    /**
     * Pops out the last element of the list.
     */
    public void pop() {
        this.tail = getNodeBeforeIndex(this.length - 1);
        this.tail.next = null;
        this.length--;
    };

    /**
     * Pops out the Node at the given index idx.
     * @param idx   int
     */
    public void popFromIndex(int idx) {
        if (!checkIndexBounds(idx)) return;

        Node pre = getNodeBeforeIndex(idx);
        Node curr = pre.next;
        pre.next = curr.next;
        this.length--;
    };
};