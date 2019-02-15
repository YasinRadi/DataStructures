#include <iostream>

// Tree Node implementation
struct Node {
    int data;
    struct Node* left, *right;
    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    };
};

class DFSTree {
    private:
        // Root of the tree
        struct Node* root;

        // In order traversal helper function.
        void inOrderHelper(const struct Node*);

        // Pre order traversal helper function.
        void preOrderHelper(const struct Node*);

        // Post order traversal helper function.
        void postOrderHelper(const struct Node*);

    public:
        // Constructor
        DFSTree() { this->root = nullptr; };

        // Insert overload to recur
        struct Node* insert(struct Node*, struct Node*);

        // Inserts a new node in the tree
        void insert(const int);

        /*
            Given a bin tree, prints its nodes according
            to the "bottom-up" inorder traversal.
                (LEFT, ROOT, RIGHT)
        */
        void inOrder(void);

        /*
            Given a bin tree, prints its nodes according
            to the "bottom-up" preorder traversal.
                (ROOT, LEFT, RIGHT)
        */
        void preOrder(void);

        /* 
            Given a bin tree, prints its nodes according
            to the "bottom-up" postorder traversal.
                (LEFT, RIGHT, ROOT)
        */
        void postOrder(void);
};

int main(void) {
    DFSTree tree;

    tree.insert(5); 
    tree.insert(3); 
    tree.insert(2); 
    tree.insert(4); 
    tree.insert(7); 
    tree.insert(6); 
    tree.insert(8);

    std::cout << "Postorder: \n";
    tree.postOrder();

    std::cout << "\nInorder:  \n";
    tree.inOrder();

    std::cout << "\nPreorder:  \n";
    tree.preOrder();

    return 0;
};

void DFSTree::postOrderHelper(const struct Node* node) {
    if (node == nullptr) return;

    // Go left first
    postOrderHelper(node->left);

    // Then go right
    postOrderHelper(node->right);

    // Finally go into node's data
    std::cout << node->data << " ";
};

void DFSTree::inOrderHelper(const struct Node* node) {
    if (node == nullptr) return;

    // First go left
    inOrderHelper(node->left);

    // Then into node's data
    std::cout << node->data << " ";

    // Finally to right child
    inOrderHelper(node->right);
};

void DFSTree::preOrderHelper(const struct Node* node) {
    if (node == nullptr) return;

    // Start with node's data
    std::cout << node->data << " ";

    // Then go left subtree
    preOrderHelper(node->left);

    // Finally right
    preOrderHelper(node->right);
};

void DFSTree::postOrder() {
    postOrderHelper(root);
};

void DFSTree::preOrder() {
    preOrderHelper(root);
};

void DFSTree::inOrder() {
    inOrderHelper(root);
};

void DFSTree::insert(const int data) {
    struct Node* node = new Node(data);
    if (root == nullptr) root = node;

    insert(root, node);
};

struct Node* DFSTree::insert(struct Node* root, struct Node* node) {
    if (root == nullptr) return node;
    
    if (node->data < root->data) {
        root->left = insert(root->left, node);
    } else if (node->data > root->data) {
        root->right = insert(root->right, node);
    }

    return root;
};

