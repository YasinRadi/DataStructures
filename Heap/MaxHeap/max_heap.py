import sys

def parent(i):
    return (i - 1) // 2
    
def left(i):
    return 2 * i + 1
    
def right(i):
    return 2 * i + 2

class MaxHeap:
    """ Max Heap implementation. """

    def __init__(self, max_cap):
        self.size = 0
        self.capacity = max_cap
        self.A = [(-sys.maxsize - 1) for _ in range(max_cap)]
    
    def getMax(self):
        return self.A[0]

    def fixHeapProperty(self, i):
        while i != 0 and self.A[parent(i)] < self.A[i]:
            self.A[i], self.A[parent(i)] = self.A[parent(i)], self.A[i]
            i = parent(i)

    def insert(self, key):
        if self.size == self.capacity:
            print('\nOverflow: could not insert key.')
            return

        # First insert the new key at the end
        self.size += 1
        i = self.size - 1
        self.A[i] = key

        # Fix heap property if violated
        self.fixHeapProperty(i)
    
    def increaseKey(self, i, new_val):
        self.A[i] = new_val
        self.fixHeapProperty(i)

    def extractMax(self):
        if self.size <= 0: return sys.maxsize
        if self.size == 1:
            self.size -= 1
            return self.A[0]

        # Store maximum value and remove it from heap
        root = self.A[0]
        self.A[0] = self.A[self.size - 1]
        self.size -= 1
        self.maxHeapify(0)

        return root
    
    def deleteKey(self, i):
        self.increaseKey(i, sys.maxsize)
        self.extractMax()
    
    def maxHeapify(self, i):
        l = left(i)
        r = right(i)
        m = i

        if l < self.size and self.A[l] > self.A[i]: m = l
        if r < self.size and self.A[r] > self.A[m]: m = r
        if m != i:
            self.A[i], self.A[m] = self.A[m], self.A[i]
            self.maxHeapify(m)
    
    def display(self):
        for i in range(self.size):
            print(self.A[i], end=' ')
        print()

if __name__ == '__main__':
    h = MaxHeap(10)
    h.insert(3)
    h.insert(2)
    h.insert(15)
    h.insert(25)
    h.insert(35)
    h.insert(7)
    h.insert(52)

    h.display()

    print('Max extracted: {0}'.format(h.extractMax()))
    print('Current max: {0}'.format(h.getMax()))

    h.display()

    h.increaseKey(1, 36)

    h.display()
