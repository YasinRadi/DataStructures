import sys

def parent(i):
    return (i - 1) // 2
    
def left(i):
    return 2 * i + 1
    
def right(i):
    return 2 * i + 2

class MinHeap:
    """ Min heap implementation clas."""

    def __init__(self, max_cap):
        self.size = 0
        self.capacity = max_cap
        self.A = [sys.maxsize for _ in range(max_cap)]
    
    def getMin(self):
        return self.A[0]

    def fixHeapProperty(self, i):
        while i != 0 and self.A[parent(i)] > self.A[i]:
            self.A[i], self.A[parent(i)] = self.A[parent(i)], self.A[i]
            i = parent(i)

    def insert(self, key):
        if self.size == self.capacity:
            print('\nOverflow: could not insert key.')
            return
        
        # First insert the new key at the end
        i = self.size
        self.size += 1
        self.A[i] = key

        # Fix the min heap property if violated
        self.fixHeapProperty(i)

    def setKey(self, i, new_val):
        self.A[i] = new_val
        self.fixHeapProperty(i)
    
    def extractMin(self):
        if self.size <= 0: return (-sys.maxsize - 1)
        if self.size == 1:
            self.size -= 1
            return self.A[0]
        
        # Store min value and remove it from heap
        root = self.A[0]
        self.size -= 1
        self.A[0] = self.A[self.size]
        self.minHeapify(0)

        return root

    def deleteKey(self, i):
        self.setKey(i, (-sys.maxsize - 1))
        self.extractMin()

    def minHeapify(self, i):
        l = left(i)
        r = right(i)
        m = i

        if l < self.size and self.A[l] < self.A[i]: m = l
        if r < self.size and self.A[r] < self.A[m]: m = r
        if m != i:
            self.A[i], self.A[m] = self.A[m], self.A[i]
            self.minHeapify(m)
    
    def display(self):
        for i in range(self.size):
            print(self.A[i], end=' ')
        print()
    

if __name__ == '__main__':
    h = MinHeap(10)
    h.insert(35)
    h.insert(3)
    h.insert(7)
    h.insert(15)
    h.insert(2)
    h.insert(25)
    h.insert(52)
    h.insert(11)
    h.insert(6)

    h.display()
    print('Min extracted: {0}'.format(h.extractMin()))
    print('Current min: {0}'.format(h.getMin()))

    h.display()

    h.setKey(3, 1)

    h.display()

    print('Min extracted: {0}'.format(h.extractMin()))
    print('Current min: {0}'.format(h.getMin()))

    h.display()