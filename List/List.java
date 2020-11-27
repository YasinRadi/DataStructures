
public class List<T> {
    // Number of items in list
    private int size;

    // Capcity of the list
    private int capacity;

    // Array that holds the list items
    private T[] items;

    public List() {
        this.size = 0;
        this.capacity = 1;
        this.items = (T[]) new Object[capacity];
    };

    public void add(T v) {
        // Increase size and check that new size fits capacity
        if (++this.size > this.capacity) {
            this.capacity *= 2;
        }

        // If capacity changed resize array
        if (this.capacity > this.items.length) {
            T[] tmp = (T[]) new Object[this.capacity];
            for (int i = 0; i < this.size - 1; i++) {
                tmp[i] = this.items[i];
            }
                
            this.items = tmp;
        }
        // Assign new element
        this.items[this.size - 1] = v;
    };

    public void display() {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < this.size; i++) {
            sb.append(items[i]).append(" ");
        }
            
        System.out.println(sb.toString());
    };

    public int size() {
        return this.size;
    };

    public T get(int idx) {
        return this.checkIndexBounds(idx) 
            ? this.items[idx] 
            : null;
    };

    public int indexOf(T t) {
        for (int i = 0; i < this.size; i++) {
            if (t == items[i]) {
                return i;
            }
        }   
        
        return -1;
    };

    public void remove(int idx) {
        if (this.checkIndexBounds(idx)) {
            for (int i = idx; i < this.size; i++) {
                items[i] = items[i + 1];
            }
                
            items[--this.size] = items[this.capacity - 1];
        }
    };

    public void remove(T t) {
        int idx = this.indexOf(t);
        if (idx != -1) {
            this.remove(idx);
        }
    };

    public boolean isEmpty() {
        return this.size == 0;
    };

    public boolean contains(T t) {
        return this.indexOf(t) != -1;
    };

    public T first() {
        return this.isEmpty() ? null : items[0];
    };

    public T last() {
        return this.isEmpty() ? null : items[this.size - 1];
    };

    public void set(int idx, T t) {
        if (this.checkIndexBounds(idx)) {
            items[idx] = t;
        }
    };

    public int capacity() {
        return this.capacity;
    };

    private boolean checkIndexBounds(int idx) {
        return idx >= 0 && idx <= this.size;
    }
};