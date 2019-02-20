using System;

public class DFSTree
{
    internal class Node
    {
        // Data held by node
        internal int data;

        // Left child of node
        internal Node left;

        // Right child of node
        internal Node right;

        // Constructor
        internal Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    // Root of tree
    private Node root;

    // Constructor
    public DFSTree() {
        this.root = null;
    }

    /// <summary>
    /// Helper that performs a BST insert.
    /// </summary>
    /// <param name="root">Root of the tree.</param>
    /// <param name="node">Node to be inserted.</param>
    /// <returns>Root of the tree.</returns>
    private Node InsertHelper(ref Node root, ref Node node) {
        // If tree empty, return node
        if (root == null) return node;

        // Otherwise, recur tree
        if (node.data < root.data) {
            root.left = InsertHelper(ref root.left, ref node);
        } else if (node.data > root.data) {
            root.right = InsertHelper(ref root.right, ref node);
        }

        // Return the node
        return root;
    }

    /// <summary>
    /// Helper function to PostOrder traversal.
    /// </summary>
    /// <param name="node">Node to start the traversal on.</param>
    private void PostOrderHelper(ref Node node) {
        if (node == null) return;

        // left 1st
        PostOrderHelper(ref node.left);

        // Right
        PostOrderHelper(ref node.right);

        // Self
        Console.Write(node.data + " ");
    }

    /// <summary>
    /// Helper function for PreOrder traversal.
    /// </summary>
    /// <param name="node">Node to start the traversal on.</param>
    private void PreOrderHelper(ref Node node) {
        if (node == null) return;

        // Self 1st
        Console.Write(node.data + " ");

        // Left
        PreOrderHelper(ref node.left);

        // Right
        PreOrderHelper(ref node.right);
    }

    /// <summary>
    /// Helper function for InOrder traversal.
    /// </summary>
    /// <param name="node">Node to start the traversal on.</param>
    private void InOrderHelper(ref Node node) {
        if (node == null) return;

        // Left 1st
        InOrderHelper(ref node.left);

        // Self
        Console.Write(node.data + " ");

        // Right
        InOrderHelper(ref node.right);
    }

    /// <summary>
    /// Given a bin tree, prints its nodes according
    /// to the "bottom-up" postorder traversal.
    /// (LEFT, RIGHT, ROOT)
    /// </summary>
    public void PostOrder() {
        PostOrderHelper(ref root);
        System.Console.WriteLine();
    }

    /// <summary>
    /// Given a bin tree, prints its nodes according
    /// to the "bottom-up" postorder traversal.
    /// (ROOT, LEFT, RIGHT)
    /// </summary>
    public void PreOrder() {
        PreOrderHelper(ref root);
        System.Console.WriteLine();
    }

    /// <summary>
    /// Given a bin tree, prints its nodes according
    /// to the "bottom-up" postorder traversal.
    /// (LEFT, ROOT, RIGHT)
    /// </summary>
    public void InOrder() {
        InOrderHelper(ref root);
        System.Console.WriteLine();
    }

    /// <summary>
    /// Creates and inserts a node for the given data.
    /// </summary>
    /// <param name="data">Data to be inserted in the tree.</param>
    public void Insert(int data) {
        // Create node to be inserted
        Node node = new Node(data);

        // Perform BST insert
        root = InsertHelper(ref root, ref node);
    }
}