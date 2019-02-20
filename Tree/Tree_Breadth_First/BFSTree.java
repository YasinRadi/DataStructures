import java.util.Queue;
import java.util.LinkedList;

/**
 * Breadth-First Binary Search Tree implementation class.
 * @author Yasin Radi
 */
public class BFSTree {

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

    // Root of the Tree
    private Node root;

    // Constructor
    public BFSTree() {
        this.root = null;
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
            root = node;
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

    /**
     * Recursive helper function for inOrder traversal.
     * @param node  Node
     */
    private void inOrderHelper(final Node node) {
        if (node == null) {
            return;
        }

        inOrderHelper(node.left);
        System.out.print(node.data + " ");
        inOrderHelper(node.right);
    };

    /**
     * Helper function for level order traversal.
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
     * Inserts a node with the given data into the tree.
     * @param data  int
     */
    public void insert(final int data) {
        // Create node to be inserted
        Node node = new Node(data);

        // Perform a normal BST insert.
        this.root = insertHelper(this.root, node);
    };

    /** InOrder traversal tree content display. */
    public void inOrder() {
        inOrderHelper(this.root);
        System.out.println();
    };

    /** Level order traversal tree content display. */
    public void levelOrder() {
        levelOrderHelper(this.root);
        System.out.println();
    };
};