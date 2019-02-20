using System;
using System.Text;
using System.Collections.Generic;

/// <summary>
/// Red Black Tree implementation class.
/// </summary>
public class RedBlackTree 
{
    // Possible colors of tree nodes.
    internal enum COLOR {
        RED, BLACK
    }

    /// <summary>
    /// Each of the tree nodes structure.
    /// </summary>
    internal class Node
    {
        // Data held by node
        internal int data;

        // Color of node
        internal COLOR color;

        // Nodes of its subtree
        internal Node left, right, parent;

        // Constructor
        internal Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
            this.parent = null;
            this.color = COLOR.RED;
        }

        public override string ToString() {
            return data.ToString();
        }
    }

    // Root of tree
    private Node root;

    // Constructor
    public RedBlackTree() {
        this.root = null;
    }

    /// <summary>
    /// Swaps the given values.
    /// </summary>
    /// <param name="t1">First value to swap.</param>
    /// <param name="t2">Second value to swap.</param>
    /// <typeparam name="T">Type of the values to be swapped.</typeparam>
    private void Swap<T>(ref T t1, ref T t2) {
        T tmp = t1;
        t1 = t2;
        t2 = tmp;
    }

    /// <summary>
    /// Performs a STD BST insert.
    /// </summary>
    /// <param name="root">Root of subtree</param>
    /// <param name="node">Node to be inserted</param>
    /// <returns>Root of subtree</returns>
    private Node InsertHelper(Node root, Node node) {
        // If tree is empty, return new node
        if (root == null) return node;

        // Otherwise, recurr down the tree
        if (node.data < root.data) {
            root.left = InsertHelper(root.left, node);
            root.left.parent = root;
        } else if (node.data > root.data) {
            root.right = InsertHelper(root.right, node);
            root.right.parent = root;
        }

        // return node
        return root;
    }

    /// <summary>
    /// Recursive helper function for inorder traversal.
    /// </summary>
    /// <param name="node">Node to display.</param>
    private void InOrderHelper(Node node) {
        if (node == null) return;

        InOrderHelper(node.left);
        System.Console.Write(node.data + " ");
        InOrderHelper(node.right);
    }

    /// <summary>
    /// Helper function for LevelOrder traversal.
    /// </summary>
    /// <param name="node">Node to start traversal in.</param>
    private void LevelOrderHelper(Node node) {
        if (node == null) return;

        Queue<Node> q  = new Queue<Node>();
        q.Enqueue(node);

        while (q.Count > 0) {
            Node tmpNode = q.Dequeue();
            System.Console.Write(tmpNode.data + " ");

            if (tmpNode.left != null) q.Enqueue(tmpNode.left);
            if (tmpNode.right != null) q.Enqueue(tmpNode.right);
        }
    }

    /// <summary>
    /// Performs a subtree left rotation starting at the
    /// given node.
    /// </summary>
    /// <param name="node">Node to perform the rotation in.</param>
    private void RotateLeft(Node node) {
        Node rightNode = node.right;
        node.right = rightNode.left;

        if (node.right != null) {
            node.right.parent = node;
        }

        rightNode.parent = node.parent;

        if (node.parent == null) {
            root = rightNode;
        } else if (node == node.parent.left) {
            node.parent.left = rightNode;
        } else {
            node.parent.right = rightNode;
        }

        rightNode.left = node;
        node.parent = rightNode;
    }

    /// <summary>
    /// Performs a subtree right rotation starting at a given node.
    /// </summary>
    /// <param name="node">Node to perform the rotation in.</param>
    private void RotateRight(Node node) {
        Node leftNode = node.left;
        node.left = leftNode.right;

        if (node.left != null) {
            node.left.parent = node;
        }

        leftNode.parent = node.parent;

        if (node.parent == null) {
            root = leftNode;
        } else if (node == node.parent.left) {
            node.parent.left = leftNode;
        }

        leftNode.right = node;
        node.parent = leftNode;
    }

    /// <summary>
    /// Performs a fix of RBTree properties to a subtree with
    /// root at the given node.
    /// </summary>
    /// <param name="node">Root of the subtree to fix.</param>
    private void FixViolation(Node node) {
        Node parentNode = null;
        Node grandParentNode = null;

        while (node != root && node.color == COLOR.RED 
            && node.parent.color == COLOR.RED)
        {
            parentNode = node.parent;
            grandParentNode = parentNode.parent;

            /* 
                CASE A:
                Parent of node is left child of grand-parent of node.
            */   
            if (parentNode == grandParentNode.left) {
                Node uncleNode = grandParentNode.right;

                /*
                    CASE 1:
                    The uncle of node is also red
                    Only recolor required
                */
                if (uncleNode != null && uncleNode.color == COLOR.RED) {
                    grandParentNode.color = COLOR.RED;
                    parentNode.color = COLOR.BLACK;
                    uncleNode.color = COLOR.BLACK;
                } else {
                    /*
                        CASE 2:
                        node is right child
                        Left-rotation required
                    */
                    if (node == parentNode.right) {
                        RotateLeft(parentNode);
                        node = parentNode;
                        parentNode = node.parent;
                    }

                    /*
                        CASE 3:
                        node is left child
                        Right-rotation required.
                    */
                    RotateRight(grandParentNode);
                    Swap(ref parentNode.color, ref grandParentNode.color);
                    node = parentNode;
                }
            /*
                CASE B:
                Parent of node is right child.
            */
            } else {
                Node uncleNode = grandParentNode.left;

                /*
                    CASE 1:
                    uncle is also red.
                    Only recolor required
                */
                if (uncleNode != null && uncleNode.color == COLOR.RED) {
                    grandParentNode.color = COLOR.RED;
                    parentNode.color = COLOR.BLACK;
                    uncleNode.color = COLOR.BLACK;
                    node = grandParentNode;
                } else {
                    /*
                        CASE 2:
                        node is left child
                        Right-rotation required
                    */
                    if (node == parentNode.left) {
                        RotateRight(parentNode);
                        node = parentNode;
                        parentNode = node.parent;
                    }

                    /*
                        CASE 3:
                        node is right child
                        Left-rotation required
                    */
                    RotateLeft(grandParentNode);
                    Swap(ref parentNode.color, ref grandParentNode.color);
                    node = parentNode;
                }
            }
        }

        root.color = COLOR.BLACK;
    }

    /// <summary>
    /// Inserts a new node to tree.
    /// </summary>
    /// <param name="data">Data held by new node.</param>
    public void Insert(int data) {
        Node node = new Node(data);
        
        // Perform BST insert.
        root = InsertHelper(root, node);

        // Fix RedBlackTree violation.
        FixViolation(node);
    }

    /// <summary>
    /// InOrder traversal tree content display.
    /// </summary>
    public void InOrder() {
        InOrderHelper(root);
        Console.WriteLine();
    }

    /// <summary>
    /// Level Order traversal tree content display.
    /// </summary>
    public void LevelOrder() {
        LevelOrderHelper(root);
        Console.WriteLine();
    }
}