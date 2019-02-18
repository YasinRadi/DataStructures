#include <iostream>

// Node struct holding T data type and pointer to next Node.
template<typename T>
struct Node {
    // Data held by the Node.
    T data; 

    // Pointer to the next Node in list.
    struct Node<T>* next = nullptr;
};

// LinkedList implementation for data type <T>.
template<typename T>
class LinkedList {
    private:
        // Head and Tail of list.
        struct Node<T>* head, *tail;

        // List length attribute.
        int length;

        // Checks if the given index is in the list's bounds.
        bool checkIndexBounds(int);

    public:
        // Constructor
        LinkedList(void);

        // Adds a node to the list created using a given
        // <T> value.
        void add(T);

        // Adds a given Node<T> to the list.
        void add(struct Node<T>*);

        // Displays the content of all nodes.
        void displayNodes(void);

        // Adds a node at the beginning of the list
        // created from a given <T> value.
        void addAtStart(T);

        // Adds a given Node<T> at the beginning of the list.
        void addAtStart(struct Node<T>*);

        // Adds a Node<T> created from a given <T> value
        // at the given index.
        void addAtIndex(int, T);

        // Adds a given Node<T> at the given index.
        void addAtIndex(int, struct Node<T>*);

        // Pops out the first element of the list.
        void popFirst(void);

        // Pops out the last element of the list.
        void pop(void);

        // Pops out the element at the given index.
        void popFromIndex(int);

        // Returns a pointer to the Node at given index minus one.
        struct Node<T>* getNodeBeforeIndex(int);
};

template<typename T>
bool LinkedList<T>::checkIndexBounds(int idx) {
    return (idx >= 0) && (idx < length);
};

template<typename T>
LinkedList<T>::LinkedList() {
    length = 0;
    head = nullptr;
    tail = nullptr;
};

template<typename T>
void LinkedList<T>::add(T v) {
    struct Node<T>* node = (struct Node<T>*)malloc(sizeof(struct Node<T>));
    node->data = v;
    node->next = nullptr;
    add(node);
};

template<typename T>
void LinkedList<T>::add(struct Node<T>* node) {
    if(head == nullptr) {
        head = node;
        tail = node;
        node = nullptr;
    } else {
        tail->next = node;
        tail = node;
    }

    length++;
};

template<typename T>
void LinkedList<T>::displayNodes() {
    struct Node<T>* node = head;
    while(node != nullptr) {
        std::cout << node->data << " ";
        node = node->next;
    };

    std::cout << std::endl;
};

template<typename T>
struct Node<T>* LinkedList<T>::getNodeBeforeIndex(int idx) {
    if(!checkIndexBounds(idx)) return nullptr;

    struct Node<T>* curr = head;
    struct Node<T>* pre = (struct Node<T>*)malloc(sizeof(struct Node<T>));
    for(int i = 0; i < idx; i++) {
        pre = curr;
        curr = curr->next;
    };

    return pre;
};

template<typename T>
void LinkedList<T>::addAtStart(T v) {
    if(head == nullptr) {
        add(v);
        return;
    }

    struct Node<T>* node = (struct Node<T>*)malloc(sizeof(struct Node<T>));
    node->data = v;
    node->next = head;
    head = node;
    length++;
};

template<typename T>
void LinkedList<T>::addAtIndex(int idx, T v) {
    if(!checkIndexBounds(idx)) return;

    struct Node<T>* node = (struct Node<T>*)malloc(sizeof(struct Node<T>));
    node->data = v;
    addAtIndex(idx, node);
};

template<typename T>
void LinkedList<T>::addAtIndex(int idx, struct Node<T>* node) {
    if(!checkIndexBounds(idx)) return;

    struct Node<T>* pre = getNodeBeforeIndex(idx);
    struct Node<T>* curr = pre->next;
    pre->next = node;
    node->next = curr;
    length++;
};

template<typename T>
void LinkedList<T>::popFirst() {
    struct Node<T>* node = head;
    head = head->next;
    delete node;
    length--;
};

template<typename T>
void LinkedList<T>::pop() {
    struct Node<T>* pre = getNodeBeforeIndex(length - 1);
    struct Node<T>* curr = pre->next;
    tail = pre;
    pre->next = nullptr;
    delete curr;
    length--;
};

template<typename T>
void LinkedList<T>::popFromIndex(int idx) {
    if(!checkIndexBounds(idx)) return;

    struct Node<T>* pre = getNodeBeforeIndex(idx);
    struct Node<T>* curr = pre->next;
    pre->next = curr->next;
    delete curr;
    length--;
};