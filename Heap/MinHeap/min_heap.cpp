#include <iostream>
#include <climits>

void swap(int*, int*);

class MinHeap {
    private:
        int* A; // Pointer of array to store heap elements
        int capacity; // Max possible size of min heap
        int heap_size; // Current number of elements

    public:
        // Constructor
        MinHeap(int);

        // Heapifies a subtree with the root at the given index.
        void minHeapify(int);

        // Return paren of A[i]
        int parent(int i) { return (i - 1) / 2; };

        // Return left child of A[i]
        int left(int i) { return 2 * i + 1; };

        // Return right child of A[i]
        int right(int i) { return 2 * i + 2; };

        // Extracts the root which is the minimum element.
        int extractMin();

        // Decreases key value of key at index i to new_val.
        void setKey(int, int);

        // Returns the min key (key at root) from min heap
        int getMin() { return A[0]; };

        // Deletes a key stored at index i
        void deleteKey(int);

        // Inserts a new key
        void insertKey(int);

        // Display the heap values
        void display();
};

MinHeap::MinHeap(int cap) {
    heap_size = 0;
    capacity = cap;
    A = new int[cap];
};

void MinHeap::insertKey(int k) {
    if(heap_size == capacity) {
        std::cout << "\nOverflow: could not insert key\n";
        return;
    }

    // First insert the new key at the end
    int i = heap_size++;
    A[i] = k;

    // Fix the min heap property if it's violated.
    while(i != 0 && A[parent(i)] > A[i]) {
        swap(&A[i], &A[parent(i)]);
        i = parent(i);
    }
};

// Decreases value of key at index 'i' to new_val. It is assumed
// that new_val is smaller than A[i].
void MinHeap::setKey(int i, int new_val) {
    A[i] = new_val;
    while(i != 0 && A[parent(i)] > A[i]) {
        swap(&A[i], &A[parent(i)]);
        i = parent(i);
    }
};

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin() {
    if(heap_size <= 0) return INT_MIN;
    if(heap_size == 1) return A[--heap_size];

    // Store minimum value and remove it from heap
    int root = A[0];
    A[0] = A[--heap_size];
    minHeapify(0);

    return root;
};

// This function deletes key at index i. It first increases value to minus 
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i) {
    setKey(i, INT_MIN);
    extractMin();
};

// A recursive method to heapify a subtree with the root at given index 
// This method assumes that the subtrees are already heapified
void MinHeap::minHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int min = i;

    if(l < heap_size && A[l] < A[i]) min = l;
    if(r < heap_size && A[r] < A[min]) min = r;
    if(min != i) {
        swap(&A[i], &A[min]);
        minHeapify(min);
    }
};

// Utility function to swap two elements
void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
};


void MinHeap::display() {
    for(int i = 0; i < heap_size; i++) std::cout << A[i] << " ";
    std::cout << "\n";
};