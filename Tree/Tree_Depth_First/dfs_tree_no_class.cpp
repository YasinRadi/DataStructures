#include <iostream>

struct Node {
    int data;
    struct Node* left, *right;
    Node(int data) {
        this->data = data;
        left = right = nullptr;
    };
};

/* 
 Given a bin tree, prints its nodes according
 to the "bottom-up" postorder traversal.
    (LEFT, RIGHT, ROOT)
 */
void printPostOrder(const struct Node*);


/*
 Given a bin tree, prints its nodes according
 to the "bottom-up" inorder traversal.
    (LEFT, ROOT, RIGHT)
*/
void printInOrder(const struct Node*);


/*
 Given a bin tree, prints its nodes according
 to the "bottom-up" preorder traversal.
    (ROOT, LEFT, RIGHT)
*/
void printPreOrder(const struct Node*);


struct Node* insertHelper(struct Node*&, struct Node*);


void insert(struct Node*, int);


void printPostOrder(const struct Node* node) {
    if (node == nullptr) return;

    // Incur first in left subtree
    printPostOrder(node->left);

    // Then go to right subtree
    printPostOrder(node->right);

    // Finally deal with the node itself
    std::cout << node->data << " ";
};

void printInOrder(const struct Node* node) {
    if (node == nullptr) return;

    // Incur first in left subtree
    printInOrder(node->left);

    // Then print the node itself
    std::cout << node->data << " ";

    // Last go to right subtree
    printInOrder(node->right);
};

void printPreOrder(const struct Node* node) {
    if (node == nullptr) return;

    // First print the node itself
    std::cout << node->data << " ";

    // Then go to left subtree
    printPreOrder(node->left);

    // Finally go to right subtree
    printPreOrder(node->right);
};

struct Node* insertHelper(struct Node*& root, struct Node* node) {
    // If tree is empty, return new node
    if (root == nullptr) return node;
    std::cout << root->data << " ";

    // Otherwise, recur down the tree
    if (node->data < root->data) {
        root->left = insertHelper(root->left, node);
    } else if (node->data < root->data) {
        root->right = insertHelper(root->right, node);
    }

    // Return subtree root
    return root;
};

void insert(struct Node* root, const int data) {
    // Create new node to be inserted
    struct Node* node = new Node(data);

    // Perform normal BST insert.
    insertHelper(root, node);
};