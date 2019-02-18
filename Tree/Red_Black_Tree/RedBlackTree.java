import java.util.Queue;
import java.util.LinkedList;

/**
 * Red Black Tree implementation class.
 * @author Yasin Radi
 */
public class RedBlackTree {

    // Possible colors of Red black tree nodes
    private enum COLOR {
        RED, BLACK
    };

    // Each of the tree nodes structure
    private class Node {
        // Data held by the node
        private int data;

        // Color of the node
        private COLOR color;

        // Nodes of its subtree
        private Node left, right, parent;

        // Node constructor
        private Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
            this.parent = null;
        };
    };

    // Root of the tree
    private Node root;

    // Tree constructor
    public RedBlackTree() {
        this.root = null;
    };

    /**
     * Performs a std bst insert.
     * @param node  Node
     * @return      Node
     */
    private Node insertHelper(Node root, Node node) {
        // If tree is empty return new node.
        if (root == null) {
            return node;
        }

        // Otherwise, recur down the tree
        if (node.data < root.data) {
            root.left = insertHelper(root.left, node);
            root.left.parent = root;
        } else if (node.data > root.data) {
            root.right = insertHelper(root.right, node);
            root.right.parent = root;
        }
        
        // Return unchanged node
        return root; 
    };

    /**
     * Recursive helper function for inorder traversal.
     * @param node  Node
     */
    private void inorderHelper(final Node node) {
        if (node == null) {
            return;
        }

        inorderHelper(node.left);
        System.out.print(node.data + " ");
        inorderHelper(node.right);
    };

    /**
     * Helper function for levelOrder traversal.
     * @param node  Node
     */
    private void levelOrderHelper(final Node node) {
        if (node == null) {
            return;
        }

        Queue<Node> q = new LinkedList<>();
        q.add(node);

        while (!q.isEmpty()) {
            Node tmpNode = q.poll();
            System.out.print(tmpNode.data + " ");
            
            if (tmpNode.left != null) {
                q.add(tmpNode.left);
            }

            if (tmpNode.right != null) {
                q.add(tmpNode.right);
            }
        }
    };

    /**
     * Performs a subtree left rotation starting 
     * at the given node.
     * @param node  Node
     */
    private void rotateLeft(Node node) {
        Node rightNode = node.right;
        node.right = rightNode.left;

        if (node.right != null)  {
            node.right.parent = node;
        }
            
        rightNode.parent = node.parent;

        if (node.parent == null) {
            this.root = rightNode;
        } else if (node == node.parent.left) {
            node.parent.left = rightNode;
        } else {
            node.parent.right = rightNode;
        }

        rightNode.left = node;
        node.parent = rightNode;
    };

    /**
     * Performs a subtree right rotation starting
     * at a given node.
     * @param node  Node
     */
    private void rotateRight(Node node) {
        Node leftNode = node.left;
        node.left = leftNode.right;

        if (node.left != null) {
            node.left.parent = node;
        }

        leftNode.parent = node.parent;

        if (node.parent == null) {
            this.root = leftNode;
        } else if (node == node.parent.left) {
            node.parent.left = leftNode;
        } else {
            node.parent.right = leftNode;
        }

        leftNode.right = node;
        node.parent = leftNode;
    };

    /**
     * Performs a fix of RBTree properties to a
     * subtree with root at the given node.
     * @param node  Node
     */
    private void fixViolation(Node node) {
        Node parentNode = null;
        Node grandParentNode = null;

        while ((node != this.root) && (node.color == COLOR.RED) 
            && (node.parent.color == COLOR.RED)) 
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
                    Only recoloring required.
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
                        rotateLeft(parentNode);
                        node = parentNode;
                        parentNode = node.parent;
                    }

                    /* 
                        CASE 3:
                        node is left child
                        Right-rotation required
                    */
                    rotateRight(grandParentNode);
                    COLOR tmpColor = parentNode.color;
                    parentNode.color = grandParentNode.color;
                    grandParentNode.color = tmpColor;
                    node = parentNode;
                }
            /* 
                CASE B:
                Parent of node is right child
            */    
            } else {
                Node uncleNode = grandParentNode.left;

                /* 
                    CASE 1:
                    uncle is also red
                    Only recoloring required
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
                        rotateRight(parentNode);
                        node = parentNode;
                        parentNode = node.parent;
                    }

                    /* 
                        CASE 3:
                        node is right child
                        Left-rotation required
                    */
                    rotateLeft(grandParentNode);
                    COLOR tmpColor = parentNode.color;
                    parentNode.color = grandParentNode.color;
                    grandParentNode.color = tmpColor;
                    node = parentNode;
                }
            }
        };

        this.root.color = COLOR.BLACK;
    };

    /**
     * Inserts a new node to tree.
     * @param data  int
     */
    public void insert(final int data) {
        Node node = new Node(data);

        // Perform a normal BST insert
        this.root = insertHelper(this.root, node);

        // Fix Red Black Tree violation
        fixViolation(node);
    };

    /** Inorder traversal tree content display. */
    public void inorder() {
        inorderHelper(this.root);
        System.out.println();
    };

    /** Level Order traversal tree content display. */
    public void levelOrder() {
        levelOrderHelper(this.root);
        System.out.println();
    };
};