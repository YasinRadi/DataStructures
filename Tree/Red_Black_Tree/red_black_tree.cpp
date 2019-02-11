#include <iostream>
#include <queue>
#include <algorithm>

enum COLOR {RED, BLACK};

struct Node {
    int data;
    bool color;
    struct Node* left, *right, *parent;

    // Constructor
    Node(int data) {
        this->data = data;
        left = right = parent = NULL;
    };
};

class RBTree {
    private:
        struct Node* root;
    
    protected:
        void rotateLeft(struct Node*, struct Node*);
        void rotateRight(struct Node*, struct Node*);
        void fixViolation(struct Node*, struct Node*);

    public:
        RBTree() { root = NULL; };
        void insert(const int&);
        void inorder();
        void levelOrder();
};

// Recursive function to do level order traversal
void inorderHelper(struct Node*);

// Utility function to insert new node with given key
struct Node* BSTInsert(struct Node*, struct Node*);

// Utility function to do level order traversal
void levelOrderHelper(struct Node*);


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


void RBTree::rotateLeft(struct Node* root, struct Node* pt) {
    struct Node* pt_right = pt->right;

    pt->right = pt_right->left;

    if(pt->right != NULL) pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if(pt->parent == NULL) root = pt_right;

    else if(pt = pt->parent->left) pt->parent->left = pt_right;

    else pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
};

void RBTree::rotateRight(struct Node* root, struct Node* pt) {
    struct Node* pt_left = pt->left;

    pt->left = pt_left->right;

    if(pt->left != NULL) pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if(pt->parent == NULL) root = pt_left;

    else if(pt == pt->parent->left) pt->parent->left = pt_left;

    else pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
};

void RBTree::fixViolation(struct Node* root, struct Node* pt) {
    struct Node* parent_pt = NULL;
    struct Node* grand_parent_pt = NULL;

    while((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        /* 
            CASE : A
            Parent of pt is left child of Grand-parent of pt.
        */
        if(parent_pt == grand_parent_pt->left) {
            struct Node* uncle_pt = grand_parent_pt->right;

            /* 
                CASE: 1
                The uncle of pt is also red
                Only recoloring required
            */
            if(uncle_pt != NULL && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                /* 
                    CASE: 2
                    pt is right child of its parent
                    Left-rotation required
                */
                if(pt == parent_pt->right) {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* 
                    CASE: 3
                    pt is left child of its parent
                    Right-rotation required
                */
                rotateRight(root, grand_parent_pt);
                std::swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        /* 
            CASE: B
            Parent of pt is right child of Grand-parent of pt.
        */    
        } else {
            struct Node* uncle_pt = grand_parent_pt->left;

            /* 
                CASE: 1
                The uncle of pt is also red
                Only recoloring required
            */
            if((uncle_pt != NULL) && (uncle_pt->color == RED)) {
                grand_parent_pt->color = RED;
                parent_pt->color = uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                /* 
                    CASE: 2
                    pt is left child of its parent
                    Right-rotation required
                */
                if(pt == parent_pt->left) {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* 
                    CASE: 3
                    pt is right child of its parent
                    Left-rotation required
                */
                rotateLeft(root, grand_parent_pt);
                std::swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root->color = BLACK;
};

void RBTree::insert(const int &data) {
    struct Node* pt = new Node(data);

    // Do a normal BST insert
    root = BSTInsert(root, pt);

    // Fix Red Black Tree Violation
    fixViolation(root, pt);
};

void RBTree::inorder() {
    inorderHelper(root);
};

void RBTree::levelOrder() {
    levelOrderHelper(root);
};

void inorderHelper(struct Node* root) {
    if(root == NULL) return;

    inorderHelper(root->left);
    std::cout << root->data << " ";
    inorderHelper(root->right);
};

void levelOrderHelper(struct Node* root) {
    if(root == NULL) return;

    std::queue<struct Node*> q;
    q.push(root);

    while(!q.empty()) {
        struct Node* tmp = q.front();
        std::cout << tmp->data << " ";
        q.pop();

        if(tmp->left != NULL) q.push(tmp->left);
        if(tmp->right != NULL) q.push(tmp->right);
    }
};

struct Node* BSTInsert(struct Node* root, struct Node* pt) {
    // If tree is empty return new node
    if(root == NULL) return pt;

    // Otherwise, recur down tree
    if(pt->data < root->data) {
        root->left = BSTInsert(root->left, pt);
        root->left->parent = root;
    } else if(pt->data > root->data) {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }

    // Return unchanged node pointer
    return root;
};