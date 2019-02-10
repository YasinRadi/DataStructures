
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

    public int getMin() {
        return this.A[0];
    };

    private void fixHeapProperty(int i) {
        while(i != 0 && this.A[parent(i)] > this.A[i]) {
            int tmp = this.A[i];
            this.A[i] = this.A[parent(i)];
            this.A[parent(i)] = tmp;
            i = parent(i);
        };
    };

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

    public void setKey(int i, int newVal) {
        this.A[i] = newVal;
        fixHeapProperty(i);
    };

    public int extractMin() {
        if(this.size <= 0) return Integer.MAX_VALUE;
        if(this.size == 1) return this.A[--this.size];

        // Store minimum value and remove it from heap
        int root = this.A[0];
        this.A[0] = this.A[--this.size];
        minHeapify(0);

        return root;
    };

    public void deleteKey(int i) {
        setKey(i, Integer.MIN_VALUE);
        extractMin();
    };

    public void minHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int min = i;

        if(l < this.size && this.A[l] < this.A[i]) min = l;
        if(l < this.size && this.A[r] < this.A[min]) min = r;
        if(min != i) {
            int tmp = this.A[i];
            this.A[i] = this.A[min];
            this.A[min] = tmp;
            minHeapify(min);
        }
    };

    public void display() {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < this.size; i++) 
            sb.append(this.A[i]).append(" ");
        System.out.println(sb.toString());
    };

    public static void main(String[] args) {
        MinHeap m = new MinHeap(10);
        m.insert(3);
        m.insert(2);
        m.insert(15);
        m.insert(25);
        m.insert(35);
        m.insert(7);
        m.insert(52);

        m.display();

        System.out.println(m.extractMin());
        System.out.println(m.getMin());

        m.display();

        m.setKey(3, 1);

        m.display();
    };
};