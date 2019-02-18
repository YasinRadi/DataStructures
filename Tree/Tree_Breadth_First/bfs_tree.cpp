#include <iostream>
#include <queue>

struct Node {
    int data;
    struct Node *left, *right;
};

// Iterative method to find height of Bin tree
void printLevelOrder(Node*);

// Utility function to create a new tree node
Node* newNode(int);

void printLevelOrder(Node* root) {
    // Base case
    if(root == NULL) return;

    // Create an empty queue for level order traversal
    std::queue<Node*> q;

    // Push the root into the queue and initialize height
    q.push(root);

    while(!q.empty()) {
        // Print front of queue and remove it from queue
        Node* node = q.front();
        std::cout << node->data << " ";
        q.pop();

        // Push into the queue left child
        if(node->left != NULL) q.push(node->left);

        // Do the same with right child
        if(node->right != NULL) q.push(node->right);
    }
};

Node* newNode(int data) {
    Node* tmp = new Node;
    tmp->data = data;
    tmp->left = tmp->right = NULL;
    return tmp;
};