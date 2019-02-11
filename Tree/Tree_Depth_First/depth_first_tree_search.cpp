#include <iostream>

struct Node {
    int data;
    struct Node* left, *right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
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


int main(void) {
    struct Node* root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    std::cout << "Postorder: \n";
    printPostOrder(root);

    std::cout << "\nInorder:  \n";
    printInOrder(root);

    std::cout << "\nPreorder:  \n";
    printPreOrder(root);

    return 0;
};

void printPostOrder(const struct Node* node) {
    if(node == NULL) return;

    // Incur first in left subtree
    printPostOrder(node->left);

    // Then go to right subtree
    printPostOrder(node->right);

    // Finally deal with the node itself
    std::cout << node->data << " ";
};

void printInOrder(const struct Node* node) {
    if(node == NULL) return;

    // Incur first in left subtree
    printInOrder(node->left);

    // Then print the node itself
    std::cout << node->data << " ";

    // Last go to right subtree
    printInOrder(node->right);
};

void printPreOrder(const struct Node* node) {
    if(node == NULL) return;

    // First print the node itself
    std::cout << node->data << " ";

    // Then go to left subtree
    printPreOrder(node->left);

    // Finally go to right subtree
    printPreOrder(node->right);
};