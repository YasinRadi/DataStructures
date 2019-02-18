#include <iostream>
#include <climits>

// Utility function to swap two elements
void swap(int*, int*);

class MaxHeap {
    private:
        int* A; // Pointer of array to store heap elements
        int capacity; // Max possible size of max heap
        int heap_size; // Current number of elements

    public:
        // Constructor
        MaxHeap(int);

        // Heapifies a subtree with the root at the given index.
        void maxHeapify(int);

        // Return paren of A[i]
        int parent(int i) { return (i - 1) / 2; };

        // Return left child of A[i]
        int left(int i) { return 2 * i + 1; };

        // Return right child of A[i]
        int right(int i) { return 2 * i + 2; };

        // Extracts the root which is the maximum element.
        int extractMax();

        // Increase key value of key at index i to new_val.
        void setKey(int, int);

        // Returns the max key (key at root) from max heap
        int getMax() { return A[0]; };

        // Deletes a key stored at index i
        void deleteKey(int);

        // Inserts a new key
        void insertKey(int);

        // Display the heap values
        void display();
};

MaxHeap::MaxHeap(int cap) {
    heap_size = 0;
    capacity = cap;
    A = new int[cap];
};

void MaxHeap::insertKey(int k) {
    if(heap_size == capacity) {
        std::cout << "\nOverflow: could not insert key\n";
        return;
    }

    // First insert the new key at the end
    int i = heap_size++;
    A[i] = k;

    // Fix the max heap property if it's violated.
    while(i != 0 && A[parent(i)] < A[i]) {
        swap(&A[i], &A[parent(i)]);
        i = parent(i);
    }
};

// Increases the value of key at index 'i' to new_val. It is assumed
// that new_val is greater than A[i].
void MaxHeap::setKey(int i, int new_val) {
    A[i] = new_val;
    while(i != 0 && A[parent(i)] < A[i]) {
        swap(&A[i], &A[parent(i)]);
        i = parent(i);
    }
};

// Method to remove maximum element (or root) from max heap
int MaxHeap::extractMax() {
    if(heap_size <= 0) return INT_MAX;
    if(heap_size == 1) {
        heap_size--;
        return A[0];
    }

    // Store maximum value and remove it from heap
    int root = A[0];
    A[0] = A[--heap_size];
    maxHeapify(0);

    return root;
};

// This function deletes key at index i. It first increases value to 
// infinite, then calls extractMax()
void MaxHeap::deleteKey(int i) {
    setKey(i, INT_MAX);
    extractMax();
};

// A recursive method to heapify a subtree with the root at given index 
// This method assumes that the subtrees are already heapified
void MaxHeap::maxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int max = i;

    if(l < heap_size && A[l] > A[i]) max = l;
    if(r < heap_size && A[r] > A[max]) max = r;
    if(max != i) {
        swap(&A[i], &A[max]);
        maxHeapify(max);
    }
};

// Utility function to swap two elements
void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
};

void MaxHeap::display() {
    for(int i = 0; i < heap_size; i++) std::cout << A[i] << " ";
    std::cout << "\n";
};