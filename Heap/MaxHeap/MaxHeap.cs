using System;
using System.Text;

/// <summary>
/// MaxHeap implementation class.
/// </summary>
public class MaxHeap 
{
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
    }

    public int Parent(int i) {
        return (i - 1) / 2;
    }

    public int Left(int i) {
        return 2 * i + 1;
    } 

    public int Right(int i) {
        return 2 * i * 2;
    }

    public int GetMax() {
        return A[0];
    }

    /// <summary>
    /// Swaps the given values.
    /// </summary>
    /// <param name="a">Value to swap.</param>
    /// <param name="b">Value to swap.</param>
    private void Swap(ref int a, ref int b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    /// <summary>
    /// Fixes Heap properties violation.
    /// </summary>
    /// <param name="i">Index of the node that needs fixing.</param>
    private void FixHeapProperty(int i) {
        while (i != 0 && A[Parent(i)] < A[i]) {
            Swap(ref A[i], ref A[Parent(i)]);
            i = Parent(i);
        }
    }

    /// <summary>
    /// Inserts a new value into the heap.
    /// </summary>
    /// <param name="k">Key of the new node.</param>
    public void Insert(int k) {
        if (heapSize == capacity) {
            Console.WriteLine("\nOverflow: Could not insert key.");
            return;
        }

        // First insert new key at end
        int i = heapSize++;
        A[i] = k;

        // Fix max heap property if violated
        FixHeapProperty(i);
    }

    /// <summary>
    /// Sets the value of the key at index 'i'
    /// to newVal. It is assumed that newVal
    /// is greater than A[i].
    /// </summary>
    /// <param name="i">Index of the node to set.</param>
    /// <param name="newVal">Value to be set.</param>
    public void SetKey(int i, int newVal) {
        A[i] = newVal;
        FixHeapProperty(i);
    }


    /// <summary>
    /// Removes the max element (or root) from max heap.
    /// </summary>
    /// <returns>Max value of heap.</returns>
    public int ExtractMax() {
        if (heapSize <= 0) return int.MaxValue;
        if (heapSize == 1) {
            heapSize--;
            return A[0];
        }

        // Store max value and remove it from heap
        int root = A[0];
        A[0] = A[--heapSize];
        MaxHeapify();

        return root;
    }

    /// <summary>
    /// Deletes a key from heap.
    /// </summary>
    /// <param name="i">Key to be deleted.</param>
    public void DeleteKey(int i) {
        SetKey(i, int.MaxValue);
        ExtractMax();
    }

    /// <summary>
    /// Resolves all max heap property violations of the heap.
    /// </summary>
    public void MaxHeapify() {
        for (int i = 0; i < heapSize; i++)
            FixHeapProperty(i);
    }

    /// <summary>
    /// Displays heap content.
    /// </summary>
    public void Display() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < heapSize; i++)
            sb.Append(A[i]).Append(" ");
        
        Console.WriteLine(sb.ToString());
    }
}