
class List:
    """ Dynamic list implementation class. """

    def __init__(self):
        self._size = 0
        self._capacity = 1
        self._items = [None for _ in range(self._capacity)]
    
    def add(self, item):
        self._size += 1
        if self._size >= self._capacity: self._capacity *= 2
        if self._capacity > len(self._items):
            tmp = [None for _ in range(self._capacity)]
            for i in range(self._size - 1):
                tmp[i] = self._items[i]
            self._items = tmp
        self._items[self._size - 1] = item
    
    def display(self):
        for i in range(self._size):
            print(self._items[i], end=' ')
        print()
    
    def size(self):
        return self._size
    
    def get(self, idx):
        return self._items[idx] if idx <= self._size else None
    
    def indexOf(self, item):
        for i in range(self._size):
            if item == self._items[i]: return i
        
        return -1
    
    def remove(self, idx=None, item=None):
        if idx is None and item is not None:
            idx = self.indexOf(item) 
        if 0 <= idx <= self._size:
            for i in range(idx, self._size - 1):
                self._items[i] = self._items[i + 1]
            self._size -= 1
            self._items[self._size] = self._items[self._capacity - 1]

    def isEmpty(self):
        return self._size == 0
    
    def contains(self, item):
        return self.indexOf(item) != -1
    
    def first(self):
        return self._items[0] if not self.isEmpty() else None
    
    def last(self):
        return self._items[self._size - 1] if not self.isEmpty() else None

    def set_(self, idx, item):
        if 0 <= idx < self._size: self._items[idx] = item

    def capacity(self):
        return self._capacity