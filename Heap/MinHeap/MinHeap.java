
class MinHeap {
    
    private int[] A;

    private int capacity;
    
    private int size;

    public MinHeap(int maxCap) {
        this.size = 0;
        this.capacity = maxCap;
        this.A = new int[maxCap];
    };

    public int parent(int i) {
        return (i - 1) / 2;
    };

    public int left(int i) {
        return i * 2 + 1;
    };

    public int right(int i) {
        return i * 2 + 2;
    };

    /**
     * Returns the min element in heap.
     * @return  int Min element of heap.
     */
    public int getMin() {
        return this.A[0];
    };

    /**
     * Fixes Heap properties violation.
     * @param i int Index of node that needs to be fixed.
     */
    private void fixHeapProperty(int i) {
        while(i != 0 && this.A[parent(i)] > this.A[i]) {
            int tmp = this.A[i];
            this.A[i] = this.A[parent(i)];
            this.A[parent(i)] = tmp;
            i = parent(i);
        };
    };

    /**
     * Inserts a new value into the heap.
     * @param key int Key of the new node.
     */
    public void insert(int key) {
        if(this.size == this.capacity) {
            System.out.println("\nOverflow: Key could not be inserted.");
            return;
        }

        // First insert the new key at the end
        int i = this.size++;
        this.A[i] = key;

        // Fix the min heap property if it's violated
        fixHeapProperty(i);
    };

    /**
     * Sets the value of the key at index 'i'
     * to newVal. It is assumed that newVal
     * is lesser than A[i]
     * @param i         int Index of node.
     * @param newVal    int Value to be set.
     */
    public void setKey(int i, int newVal) {
        this.A[i] = newVal;
        fixHeapProperty(i);
    };

    /**
     * Removes the min element (or root) from min heap.
     * @return int  Min value of heap.
     */
    public int extractMin() {
        if(this.size <= 0) {
            return Integer.MIN_VALUE;
        }

        if(this.size == 1) {
            return this.A[--this.size];
        }

        // Store minimum value and remove it from heap
        int root = this.A[0];
        this.A[0] = this.A[--this.size];
        minHeapify();

        return root;
    };

    /**
     * Deletes a key from heap.
     * @param i int Key to be deleted.
     */
    public void deleteKey(int i) {
        setKey(i, Integer.MIN_VALUE);
        extractMin();
    };

    /**
     * Resolves all min heap properties violations.
     */
    public void minHeapify() {
        for (int i = 0; i < this.heapSize; i++) {
            fixHeapProperty(i);
        }
    };

    /**
     * Displays heap content.
     */
    public void display() {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < this.size; i++) 
            sb.append(this.A[i]).append(" ");
        System.out.println(sb.toString());
    };
};