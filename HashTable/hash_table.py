
class HashNode:
    """ HashNode class implementation.
    
    Attributes:
    -----------
    key : int
        Key of map entry.
    
    value : int
        Value of map entry.
    
    Parameters:
    -----------
    k : int
        Key of the entry.
    
    v : int
        Value of the entry.

     """
    def __init__(self, k, v):
        self.key = k
        self.value = v
    
class HashTable:
    """ HashTable / HashMap implementation class.
    
    Attributes:
    -----------
    m : list<HashNode>
        List of map entries
    
    _size : int
        Size of the map.
    
    TABLE_SIZE : int
        Max entry num.
    
    """
    TABLE_SIZE = 128

    def __init__(self):
        self.m = [None for _ in range(self.TABLE_SIZE)]
        self._size = 0
    
    def _hashFunc(self, k):
        """ Hash function. 

        Parameters:
        -----------
        k : int
            Key to hash.
        
        Returns:
            An int hash value.

        """
        return k % self.TABLE_SIZE
    
    def insert(self, k, v):
        """ Insert a new map entry into the map.

        Parameters:
        -----------
        k : int
            Key to be inserted.
        
        v : int
            Value to be inserted

        """
        hash_ = self._hashFunc(k)
        while self.m[hash_] is not None and self.m[hash_].key != k:
            hash_ = self._hashFunc(hash_ + 1)
        
        self._size += 1
        self.m[hash_] = HashNode(k, v)
    
    def get(self, k):
        """ Retrieve from map the element related to the given key.

        Parameters:
        -----------
        k : int
            Key to retrieve the value.
        
        Returns:
        --------
            Value mapped to k.
        
        """
        hash_ = self._hashFunc(k)
        while self.m[hash_] is not None and self.m[hash_].key != k:
            hash_ = self._hashFunc(hash_ + 1)
        
        return self.m[hash_].value if self.m[hash_] is not None else -1
    
    def contains(self, k):
        """ Check if given key is in map. 

        Parameters:
        -----------
        k : int
            Key to check.
        
        Returns:
            True if key is in map. False otherwise.

        """
        return self.get(k) != -1
    
    def display(self):
        """ Display map<K, V> content. """
        for n in self.m:
            if n is not None:
                print('{{K: {0}, V: {1}}}'.format(n.key, n.value))
    
    def remove(self, k):
        """ Remove a <K, V> from map given a K.

        Parameters:
        -----------
        k : int
            Key of value to remove.
        
        """
        hash_ = self._hashFunc(k)
        while self.m[hash_] is not None:
            if self.m[hash_].key != k:
                hash_ = self._hashFunc(hash_ + 1)
                continue
            
            break
        
        if self.m[hash_] is None:
            return
        
        self._size -= 1
        self.m[hash_] = None
    
    def size(self):
        """ Size of map. """
        return self._size