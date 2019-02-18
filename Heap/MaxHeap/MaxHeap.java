
/**
 * Max Heap implementation class.
 */
public class MaxHeap {
    
    // Array to store heap elements
    private int[] A;

    // Max possible size of max heap
    private int capacity;

    // Current number of elements
    private int heapSize;

    public MaxHeap(int cap) {
        this.heapSize = 0;
        this.capacity = cap;
        this.A = new int[cap];
    };

    public int parent(int i) {
        return (i - 1) / 2;
    };

    public int left(int i) {
        return 2 * i + 1;
    };

    public int right(int i) {
        return 2 * i + 2;
    };

    public int getMax() {
        return this.A[0];
    };

    /**
     * Fix Heap properties violation.
     * @param i     Index upon to fix the violation.
     */
    private void fixHeapProperty(int i) {
        while (i != 0 && this.A[parent(i)] < this.A[i]) {
            int tmp = this.A[i];
            this.A[i] = this.A[parent(i)];
            this.A[parent(i)] = tmp;
            i = parent(i);
        }
    };

    /**
     * Inserts a new value into the heap.
     * @param key   Value to be inserted in heap.
     */
    public void insert(int key) {
        if (this.heapSize == this.capacity) {
            System.out.println("\nOverflow: could not insert key.");
            return;
        }

        // First insert the new key at the end
        int i = this.heapSize++;
        this.A[i] = key;

        // Fix max heap property if it's violated.
        fixHeapProperty(i);
    };

    /**
     * Increases the value of the key at index 'i' to newVal.
     * It's assumed that newVal is greater than A[i].
     * @param i      int
     * @param newVal int
     */
    public void setKey(int i, int newVal) {
        this.A[i] = newVal;
        fixHeapProperty(i);
    };

    /**
     * Removes the maximum element (or root) from max heap.
     * @return  int
     */
    public int extractMax() {
        if(this.heapSize <= 0) return Integer.MAX_VALUE;
        if(this.heapSize == 1) {
            this.heapSize--;
            return this.A[0];
        };

        // Store maximum value and remove it from heap.
        int root = this.A[0];
        this.A[0] = this.A[--this.heapSize];
        this.maxHeapify(0);

        return root;
    };

    /**
     * Deletes a key at index 'i'.
     * Increases value to +INF, then calls extractMax()
     * @param i int
     */
    public void deleteKey(int i) {
        this.setKey(i, Integer.MAX_VALUE);
        this.extractMax();
    };

    /**
     * Recursive method to heapify a subtree with the root at the given
     * index. Assumes that the subtrees are already heapified.
     * @param i int
     */
    public void maxHeapify(int i) {
        int l = this.left(i);
        int r = this.right(i);
        int max = i;

        if (l < this.heapSize && this.A[l] > this.A[i]) {
            max = l;
        }

        if (r < this.heapSize && this.A[r] > this.A[max]) {
            max = r;
        }
        
        if(max != i) {
            int tmp = this.A[max];
            this.A[max] = this.A[i];
            this.A[i] = tmp;
            this.maxHeapify(max);
        }
    };

    public void display() {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < this.heapSize; i++)
            sb.append(this.A[i]).append(" ");
        System.out.println(sb.toString());
    };
};