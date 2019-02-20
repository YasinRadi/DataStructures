

/**
 * Depth-First Binary Search Tree implementation class.
 * @author Yasin Radi
 */
public class DFSTree {

    /** Tree Node implementation. */
    private class Node {
        // Data held by the node
        private int data;

        // Left child of node
        private Node left;

        // Right child of node
        private Node right;

        private Node(int data) {
            this.data = data;
            this.right = null;
            this.left = null;
        };
    };

    // Root of the tree
    private Node root;

    public DFSTree() {
        this.root = null;
    };

    /**
     * Inserts a node with the given data into the tree.
     * @param data  int
     */
    public void insert(final int data) {
        // Create node to be inserted
        Node node = new Node(data);

        // Perform a normal BST insert.
        this.root = insertHelper(this.root, node);
    };

    /**
     * Helper that performs a std BST insert.
     * @param root  Node
     * @param node  Node
     * @return      Node
     */
    private Node insertHelper(Node root, Node node) {
        // If tree is empty, return new node
        if (root == null) {
            return node;
        }

        // Otherwise, recur down the tree
        if (node.data < root.data) {
            root.left = insertHelper(root.left, node);
        } else if (node.data > root.data) {
            root.right = insertHelper(root.right, node);
        }

        // Return the unchanged node
        return root;
    };

    /** Helper function to postOrder traversal. */
    private void postOrderHelper(final Node node) {
        if (node == null) {
            return;
        }

        // Incur first in left subtree
        postOrderHelper(node.left);

        // Then go right subtree
        postOrderHelper(node.right);

        // Finally deal with the node itself
        System.out.print(node.data + " ");
    };

    /** Helper function for preOrder traversal. */
    private void preOrderHelper(final Node node) {
        if (node == null) {
            return;
        }

        // Start with the node's data
        System.out.print(node.data + " ");

        // Then go left subtree
        preOrderHelper(node.left);

        // Finally right
        preOrderHelper(node.right);
    };

    /** Helper function for inOrder traversal. */
    private void inOrderHelper(final Node node) {
        if (node == null) {
            return;
        }

        // Incur first in left subtree
        inOrderHelper(node.left);

        // Then print the data in the node
        System.out.print(node.data + " ");

        // Then go right
        inOrderHelper(node.right);
    };

    /**
     * Given a bin tree, prints its nodes according
     * to the "bottom-up" postorder traversal.
     * (LEFT, RIGHT, ROOT)
     */
    public void postOrder() {
        postOrderHelper(this.root);
        System.out.println();
    };

    /**
     * Given a bin tree, prints its nodes according
     * to the "bottom-up" inorder traversal.
     * (LEFT, ROOT, RIGHT)
     */
    public void inOrder() {
        inOrderHelper(this.root);
        System.out.println();
    };

    /**
     * Given a bin tree, prints its nodes according
     * to the "bottom-up" preorder traversal.
     * (ROOT, LEFT, RIGHT)
     */
    public void preOrder() {
        preOrderHelper(this.root);
        System.out.println();
    };
};