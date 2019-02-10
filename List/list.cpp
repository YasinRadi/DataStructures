#include <iostream>

template<typename T>
class List {
    private:
        // Num of items in list
        int num;

        // Capacity of the list
        int capacity;

        // Array that holds the 
        // list items 
        T* items;
    
    public:
        List(void);

        // Add a new value to the list
        void add(T);

        // Get the value at index n
        T get(int);

        // Remove the item at
        // index n 
        void remove(int);

        // Remove the given
        // item
        void remove(T*);

        // Return the size of the list
        int size(void);

        // Return true if list is empty
        bool isEmpty(void);

        // Whether or not the list
        // contains the given item
        bool contains(T*);

        // Returns the index of the
        // given element
        int indexOf(T);

        // Returns the index of
        // the given pointer
        // to an element
        int indexOf(T*);

        // Set the item at given idx
        // to the given item
        void set(int, T*);

        // Return first item
        T first(void);

        // Return last item
        T last(void);

        // Display contained items
        void display(void);

        // Return real capacity of list
        int cap(void);
};

int main(void) {
    List<int> l;

    std::cout << "Is empty: " << l.isEmpty() << "\n";

    for(int i = 0; i < 10; i++)
        l.add(i * i * i);

    l.display();

    std::cout << "Size: " << l.size() << "\n";
    
    l.remove(1);
    l.display();
    std::cout << "Size: " << l.size() << "\n";
    int x = 8;
    int* p = &x;
    std::cout << "Contains 8: " << l.contains(p) << "\n";
    std::cout << "First: " << l.first() << "\n";
    std::cout << "Last: " << l.last() << "\n";
    std::cout << "Real capacity: " << l.cap() << "\n";

    return 0;
};

template<typename T>
List<T>::List() {
    capacity = 0;
    num = 0;
    items = new T[++capacity];
};

template<typename T>
void List<T>::add(T v) {
    if(++num >= capacity) capacity *= 2;
    if(capacity > (sizeof(items) / sizeof(T))) {
        T* tmp = new T[capacity];
        for(int i = 0; i < num - 1; i++)
            tmp[i] = items[i];
        items = tmp;
    }
    items[num - 1] = v;
};

template<typename T>
void List<T>::display(void) {
    for(int i = 0; i < num; i++)
        std::cout << items[i] << " ";
    std::cout << "\n";
};

template<typename T>
int List<T>::size(void) {
    return num;
};

template<typename T>
T List<T>::get(int idx) {
    return idx <= num ? items[idx] : NULL;
};

template<typename T>
int List<T>::indexOf(T* t) {
    for(int i = 0; i < num; i++)
        if(*t == items[i]) return i;

    return -1;
};

template<typename T>
int List<T>::indexOf(T t) {
    return indexOf(&t);
};

template<typename T>
void List<T>::remove(int idx) {
    if(idx <= num) {
        for(int i = idx; i < num - 1; i++)
            items[i] = items[i + 1];
        items[--num] = items[capacity - 1];
    }
};

template<typename T>
void List<T>::remove(T* t) {
    int idx = indexOf(t);
    if(idx != -1) remove(idx);
};

template<typename T>
bool List<T>::isEmpty(void) {
    return num == 0;
};

template<typename T>
bool List<T>::contains(T* t) {
    return indexOf(t) != -1;
};

template<typename T>
T List<T>::first(void) {
    return isEmpty() ? NULL : items[0];
};

template<typename T>
T List<T>::last(void) {
    return isEmpty() ? NULL : items[num - 1];
};

template<typename T>
void List<T>::set(int idx, T* t) {
    if(idx <= num) items[idx] = *t;
};

template<typename T>
int List<T>::cap(void){
    return capacity;
}