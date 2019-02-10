#include <iostream>

template<typename T>
struct Node {
    T data;
    struct Node<T>* next = nullptr;
};

template<typename T>
class LinkedList {
    private:
        struct Node<T>* head, *tail;
        int length;

    public:
        LinkedList(void);
        void add(T);
        void add(struct Node<T>*);
        void displayNodes(void);
        void addAtStart(T);
        void addAtStart(struct Node<T>*);
        void addAtIndex(int, T);
        void addAtIndex(int, struct Node<T>*);
        void popFirst(void);
        void pop(void);
        void popFromIndex(int);
        struct Node<T>* getNodeBeforeIndex(int);
};

int main(void) {
    LinkedList<int> list;

    for(int i = 0; i < 10; i++) list.add(i);
    list.displayNodes();

    list.addAtIndex(3, 77);
    list.addAtStart(55);

    list.displayNodes();
    list.popFromIndex(2);
    list.pop();

    list.displayNodes();
    return 0;
};

template<typename T>
LinkedList<T>::LinkedList() {
    length = 0;
    head = nullptr;
    tail = nullptr;
};

template<typename T>
void LinkedList<T>::add(T v) {
    struct Node<T>* tmp = (struct Node<T>*)malloc(sizeof(struct Node<T>));
    tmp->data = v;
    tmp->next = nullptr;

    if(head == nullptr) head = tmp;
    else tail->next = tmp;

    tail = tmp;
    length++;
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
    struct Node<T>* curr = (struct Node<T>*)malloc(sizeof(struct Node<T>));
    struct Node<T>* pre = (struct Node<T>*)malloc(sizeof(struct Node<T>));
    curr = head;
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
    struct Node<T>* node = (struct Node<T>*)malloc(sizeof(struct Node<T>));
    node->data = v;
    addAtIndex(idx, node);
};

template<typename T>
void LinkedList<T>::addAtIndex(int idx, struct Node<T>* node) {
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
    struct Node<T>* pre = getNodeBeforeIndex(idx);
    struct Node<T>* curr = pre->next;
    pre->next = curr->next;
    delete curr;
    length--;
};