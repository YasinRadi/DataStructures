/**
 * LinkedList implementation for data type <T>.
 * @author Yasin Radi
 */
public class LinkedList<T> {

    /**
     * Node class holding T data type implementation.
     * @param <T>   Type of the data
     */
    private class Node<T> {
        // Data held by the node.
        public T data;

        // Pointer to the next node in the list.
        public Node<T> next;

        // Node constructor
        public Node() {
            this.data = null;
            this.next = null;
        };

        public Node(T v) {
            this.data = v;
            this.next = null;
        };

        public Node(T v, Node<T> next) {
            this.data = v;
            this.next = next;
        };
    };

    // Head node.
    private Node<T> head;

    // Tail node.
    private Node<T> tail;

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
     * @param node  Node<T>
     */
    public void add(Node<T> node) {
        if(this.head == null) {
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
        Node<T> node = new Node<>(v);
        add(node);
    };

    /**
     * Displays the content of all nodes.
     */
    public void displayNodes() {
        Node<T> node = this.head;
        StringBuilder sb = new StringBuilder();
        while(node != null) {
            sb.append(node.data).append(" ");
            node = node.next;
        };

        System.out.println(sb.toString());
    };

    /**
     * Gets the node before the given index.
     * @param idx   int
     * @return      Node<T>
     */
    public Node<T> getNodeBeforeIndex(int idx) {
        if(!checkIndexBounds(idx)) return null;

        Node<T> curr = this.head;
        Node<T> pre = new Node<>();
        for(int i = 0; i < idx; i++) {
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
        if(this.head == null) {
            add(v);
            return;
        };

        Node<T> node = new Node<>(v, this.head);
        this.head = node;
        this.length++;
    };

    /**
     * Adds a given Node<T> at the beginning of the list.
     * @param node  Node<T>
     */
    public void addAtStart(Node<T> node) {
        if(this.head == null) {
            add(node);
            return;
        };

        node.next = this.head;
        this.head = node;
        this.length++;
    };

    /**
     * Adds a given Node<T> at the given index idx.
     * @param idx   int
     * @param node  Node<T>
     */
    public void addAtIndex(int idx, Node<T> node) {
        if(!checkIndexBounds(idx)) return;

        Node<T> pre = getNodeBeforeIndex(idx);
        Node<T> curr = pre.next;
        pre.next = node;
        node.next = curr;
        this.length++;
    };

    /**
     * Adds a given Node<T> created from <T> value v
     * at the given index idx.
     * @param idx   int
     * @param v     <T>
     */
    public void addAtIndex(int idx, T v) {
        if(!checkIndexBounds(idx)) return;

        Node<T> node = new Node<>(v);
        addAtIndex(idx, node);
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
     * Pops out the Node<T> at the given index idx.
     * @param idx   int
     */
    public void popFromIndex(int idx) {
        if(!checkIndexBounds(idx)) return;

        Node<T> pre = getNodeBeforeIndex(idx);
        Node<T> curr = pre.next;
        pre.next = curr.next;
        this.length--;
    };
};