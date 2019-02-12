#include <iostream>
#include <queue>
#include <algorithm>

// Possible colors of Red black tree nodes
enum COLOR {RED, BLACK};

// Each of the tree nodes structure
struct Node {
    int data;
    COLOR color;
    struct Node* left, *right, *parent;

    // Constructor
    Node(int data) {
        this->data = data;
        left = right = parent = nullptr;
    };
};

// Red Black Tree implementation class.
class RBTree {
    private:
        // Root of the tree
        struct Node* root;

        // Recursive function to do level order traversal
        void inorderHelper(struct Node*);

        // Utility function to insert new node with given key
        struct Node* insertHelper(struct Node*, struct Node*);

        // Utility function to do level order traversal
        void levelOrderHelper(struct Node*);

        // Performs a subtree left rotation starting 
        void rotateLeft(struct Node*, struct Node*);

        // Performs a subtree right rotation starting 
        void rotateRight(struct Node*, struct Node*);

        // Performs a fix of RBTree properties to a
        // subtree with root at the given node.
        void fixViolation(struct Node*, struct Node*);

    public:
        // Constructor
        RBTree() { root = nullptr; };

        // Inserts a new node to tree.
        void insert(const int&);

        // Inorder traversal tree content display.
        void inorder();

        // Level Order traversal tree content display.
        void levelOrder();
};

int main(void) {
    RBTree tree;

    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);

    std::cout << "Inorder traversal of tree:\n";
    tree.inorder();

    std::cout << "\nLevel Order traversal of tree:\n";
    tree.levelOrder();
    
    return 0;
};


void RBTree::rotateLeft(struct Node* root, struct Node* node) {
    struct Node* rightNode = node->right;
    node->right = rightNode->left;

    if (node->right != nullptr) {
        node->right->parent = node;
    }

    rightNode->parent = node->parent;

    if (node->parent == nullptr) {
        root = rightNode;
    } else if (node == node->parent->left) {
        node->parent->left = rightNode;
    } else {
        node->parent->right = rightNode;
    }

    rightNode->left = node;
    node->parent = rightNode;
};

void RBTree::rotateRight(struct Node* root, struct Node* node) {
    struct Node* leftNode = node->left;
    node->left = leftNode->right;

    if (node->left != nullptr) {
        node->left->parent = node;
    }

    leftNode->parent = node->parent;

    if (node->parent == nullptr) {
        root = leftNode;
    } else if (node == node->parent->left) {
        node->parent->left = leftNode;
    } else {
        node->parent->right = leftNode;
    }

    leftNode->right = node;
    node->parent = leftNode;
};

void RBTree::fixViolation(struct Node* root, struct Node* node) {
    struct Node* parentNode = nullptr;
    struct Node* grandParentNode = nullptr;

    while(node != root && node->color == RED && node->parent->color == RED) {
        parentNode = node->parent;
        grandParentNode = node->parent->parent;

        /* 
            CASE : A
            Parent of node is left child of Grand-parent of node.
        */
        if (parentNode == grandParentNode->left) {
            struct Node* uncleNode = grandParentNode->right;

            /* 
                CASE: 1
                The uncle of node is also red
                Only recoloring required
            */
            if (uncleNode != nullptr && uncleNode->color == RED) {
                grandParentNode->color = RED;
                parentNode->color = uncleNode->color = BLACK;
                node = grandParentNode;
            } else {
                /* 
                    CASE: 2
                    node is right child of its parent
                    Left-rotation required
                */
                if (node == parentNode->right) {
                    rotateLeft(root, parentNode);
                    node = parentNode;
                    parentNode = node->parent;
                }

                /* 
                    CASE: 3
                    node is left child of its parent
                    Right-rotation required
                */
                rotateRight(root, grandParentNode);
                std::swap(parentNode->color, grandParentNode->color);
                node = parentNode;
            }
        /* 
            CASE: B
            Parent of node is right child of Grand-parent of node.
        */    
        } else {
            struct Node* uncleNode = grandParentNode->left;

            /* 
                CASE: 1
                The uncle of node is also red
                Only recoloring required
            */
            if ((uncleNode != nullptr) && (uncleNode->color == RED)) {
                grandParentNode->color = RED;
                parentNode->color = uncleNode->color = BLACK;
                node = grandParentNode;
            } else {
                /* 
                    CASE: 2
                    node is left child of its parent
                    Right-rotation required
                */
                if (node == parentNode->left) {
                    rotateRight(root, parentNode);
                    node = parentNode;
                    parentNode = node->parent;
                }

                /* 
                    CASE: 3
                    node is right child of its parent
                    Left-rotation required
                */
                rotateLeft(root, grandParentNode);
                std::swap(parentNode->color, grandParentNode->color);
                node = parentNode;
            }
        }
    }

    root->color = BLACK;
};

void RBTree::insert(const int &data) {
    struct Node* node = new Node(data);

    // Do a normal BST insert
    root = insertHelper(root, node);

    // Fix Red Black Tree Violation
    fixViolation(root, node);
};

void RBTree::inorder() {
    inorderHelper(root);
};

void RBTree::levelOrder() {
    levelOrderHelper(root);
};

void RBTree::inorderHelper(struct Node* root) {
    if (root == nullptr) return;

    inorderHelper(root->left);
    std::cout << root->data << " ";
    inorderHelper(root->right);
};

void RBTree::levelOrderHelper(struct Node* root) {
    if (root == nullptr) return;

    std::queue<struct Node*> q;
    q.push(root);

    while (!q.empty()) {
        struct Node* tmp = q.front();
        std::cout << tmp->data << " ";
        q.pop();

        if (tmp->left != nullptr) q.push(tmp->left);
        if (tmp->right != nullptr) q.push(tmp->right);
    }
};

struct Node* RBTree::insertHelper(struct Node* root, struct Node* node) {
    // If tree is empty return new node
    if (root == nullptr) {
        root = node;
        return node;
    }

    // Otherwise, recur down tree
    if (node->data < root->data) {
        root->left = insertHelper(root->left, node);
        root->left->parent = root;
    } else if (node->data > root->data) {
        root->right = insertHelper(root->right, node);
        root->right->parent = root;
    }

    // Return unchanged node pointer
    return root;
};