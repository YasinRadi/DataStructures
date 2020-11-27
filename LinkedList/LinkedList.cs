using System;
using System.Text;

/// <summary>
/// LinkedList implementation for data type < T >.
/// </summary>
public class LinkedList<T>
{
    /// <summary>
    /// Node class holding T data type implementation.
    /// </summary>
    /// <typeparam name="T">Type of data held by list.</typeparam>
    protected class Node
    {
        // Data held by node
        public T data;

        // Pointer to next node in list
        public Node next;

        // Constructor
        public Node() {
            this.data = default(T);
            this.next = null;
        }

        public Node(T v) {
            this.data = v;
            this.next = null;
        }

        public Node(T v, Node next) {
            this.data = v;
            this.next = next;
        }
    }

    // Head node.
    private Node head;

    // Tail node.
    private Node tail;

    // List's length attribute.
    private int length;

    public LinkedList() {
        this.length = 0;
        this.head = null;
        this.tail = null;
    }

    /// <summary>
    /// Checks if the given index is in list's bounds.
    /// </summary>
    /// <param name="idx">Index to check</param>
    /// <returns>True if is in list bounds, false otherwise.</returns>
    protected bool CheckIndexBounds(int idx) {
        return idx >= 0 && idx <= length;
    }

    /// <summary>
    /// Adds a given node to the list.
    /// </summary>
    /// <param name="node">Node to be added to list.</param>
    protected void Add(Node node) {
        if (head == null) {
            head = node;
            tail = node;
        } else {
            tail.next = node;
            tail = node;
        }

        length++;
    }

    /// <summary>
    /// Adds a node to the list given a value of type < T >.
    /// </summary>
    /// <param name="v">Value to be added to the list.</param>
    public void Add(T v) {
        Add(new Node(v));
    }

    /// <summary>
    /// Displays the content of all nodes.
    /// </summary>
    public void Display() {
        Node node = head;
        StringBuilder sb = new StringBuilder();
        while (node != null) {
            sb.Append(node.data).Append(" ");
            node = node.next;
        }

        Console.WriteLine(sb.ToString());
    }

    /// <summary>
    /// Gets the node before the given index.
    /// </summary>
    /// <param name="idx">Index consequtive to the desired node.</param>
    /// <returns>The node before the given index.</returns>
    protected Node GetNodeBeforeIndex(int idx) {
        if (!CheckIndexBounds(idx)) return null;

        Node curr = head;
        Node pre = new Node();
        for (int i = 0; i < idx; i++) {
            pre = curr;
            curr = curr.next;
        }

        return pre;
    }

    /// <summary>
    /// Adds a node at the beginning of the list
    /// created from a given < T > value.
    /// </summary>
    /// <param name="v">Value of the new node.</param>
    public void AddAtStart(T v) {
        if (head == null) {
            Add(v);
            return;
        }

        Node node = new Node(v, head);
        head = node;
        length++;
    }

    /// <summary>
    /// Adds a given Node< T > at the given index idx.
    /// </summary>
    /// <param name="idx">Index where the new node will be added.</param>
    /// <param name="node">Node to be added.</param>
    protected void AddAtIndex(int idx, Node node) {
        if (!CheckIndexBounds(idx)) return;

        Node pre = GetNodeBeforeIndex(idx);
        Node curr = pre.next;
        pre.next = node;
        node.next = curr;
        length++;
    }

    /// <summary>
    /// Adds a given value v at the given index idx.
    /// </summary>
    /// <param name="idx">Index where the new node will be added.</param>
    /// <param name="v">Value to be added.</param>
    public void AddAtIndex(int idx, T v) {
        AddAtIndex(idx, new Node(v));
    }

    /// <summary>
    /// Pops out the first element of the list.
    /// </summary>
    public void PopFirst() {
        head = head.next;
        length--;
    }

    /// <summary>
    /// Pops out the last element of the list.
    /// </summary>
    public void Pop() {
        tail = GetNodeBeforeIndex(length - 1);
        tail.next = null;
        length--;
    }

    /// <summary>
    /// Pops out the element at the given index idx.
    /// </summary>
    /// <param name="idx">Index of the element to be popped out.</param>
    public void PopFromIndex(int idx) {
        if (!CheckIndexBounds(idx)) return;

        Node pre = GetNodeBeforeIndex(idx);
        Node curr = pre.next;
        pre.next = curr.next;
        length--;
    }
}