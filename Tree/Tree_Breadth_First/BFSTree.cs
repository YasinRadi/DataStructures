using System;
using System.Text;
using System.Collections.Generic;

/// <summary>
/// Breadth-First Binary Search Tree implementation class.
/// </summary>
public class BFSTree
{
    /// <summary>
    /// Tree Node implementation.
    /// </summary>
    internal class Node
    {
        // Data held by the node
        internal int data;

        // Left child of node
        internal Node left;

        // Right child of node
        internal Node right;

        // Constructor
        internal Node(int data) {
            this.data = data;
            this.right = null;
            this.left = null;
        }
    }

    // Root of the Tree
    private Node root;

    // Constructor
    public BFSTree() {
        this.root = null;
    }

    /// <summary>
    /// Helper that performs a STD BST insert.
    /// </summary>
    /// <param name="root">Root of the tree.</param>
    /// <param name="node">Node to be inserted.</param>
    /// <returns></returns>
    private Node InsertHelper(ref Node root, ref Node node) {
        // If tree is empty, return new node
        if (root == null) {
            root = node;
            return node;
        }

        // Otherwise, recur down tree
        if (node.data < root.data) {
            root.left = InsertHelper(ref root.left, ref node);
        } else if (node.data > root.data) {
            root.right = InsertHelper(ref root.right, ref node);
        }

        // Return root
        return root;
    }

    /// <summary>
    /// Helper function for InOrder traversal.
    /// </summary>
    /// <param name="node">Node to start displaying at.</param>
    private void InOrderHelper(ref Node node) {
        if (node == null) return;

        InOrderHelper(ref node.left);
        Console.Write(node.data + " ");
        InOrderHelper(ref node.right);
    }

    /// <summary>
    /// Helper function for LevelOrder traversal.
    /// </summary>
    /// <param name="node">Node to start displaying at.</param>
    private void LevelOrderHelper(ref Node node) {
        if (node == null) return;

        Queue<Node> q = new Queue<Node>();
        q.Enqueue(node);

        while (q.Count > 0) {
            Node tmpNode = q.Dequeue();
            System.Console.Write(tmpNode.data + " ");

            if (tmpNode.left != null) q.Enqueue(tmpNode.left);
            if (tmpNode.right != null) q.Enqueue(tmpNode.right);
        }
    }

    /// <summary>
    /// Inserts a node with the given data into the tree.
    /// </summary>
    /// <param name="data"></param>
    public void Insert(int data) {
        // Create node to be inserted
        Node node = new Node(data);

        // Perform BST insert
        root = InsertHelper(ref root, ref node);
    }

    /// <summary>
    /// InOrder traversal tree content display.
    /// </summary>
    public void InOrder() {
        InOrderHelper(ref root);
        System.Console.WriteLine();
    }

    /// <summary>
    /// LevelOrder traversal tree content display.
    /// </summary>
    public void LevelOrder() {
        LevelOrderHelper(ref root);
        System.Console.WriteLine();
    }
}