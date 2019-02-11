
class Node:
    """ LinkedList Node implementation class.
    
    Attributes:
    ----------
    data : object
        Data held by the Node.
    
    next : Node
        Pointer to the next Node in the list.

    """

    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next
    
class LinkedList:
    """ LinkedList implementation class. 
    
    Attributes:
    ----------
    length : int
        Length of the list.
    
    head : Node
        Head of the list.
    
    tail : Node
        Tail of the list.

    """

    def __init__(self):
        self.length = 0
        self.head : Node = None
        self.tail : Node = None

    def checkIndexBounds(self, idx):
        """ Checks if the given index is in the
            list's bounds.
        
        Parameters:
        ----------
        idx : int
            Index to be checked
        
        Returns:
        --------
            True if the index is list's bounds.
            False otherwise.
        
        """
        return idx >= 0 and idx < self.length
    
    def add(self, value=None, node=None):
        """ Adds the given Node to the list
            if node is not None, or creates it
            if value is not None.

            Parameters:
            ----------
            value : object
                Value held by the Node.
            
            node : Node
                Node to be added to the list.

        """
        tmp = None
        
        if value is not None:
            tmp = Node(value)
        elif node is not None:
            tmp = node
        
        if self.head is None:
            self.head = tmp
        else:
            self.tail.next = tmp
        
        self.tail = tmp
        self.length += 1
    
    def displayNodes(self):
        """ Displays the content of all nodes. """

        node = self.head
        while node is not None:
            print(node.data, end=' ')
            node = node.next
        print()
    
    def getNodeBeforeIndex(self, idx):
        """ Returns the node at the given index minus one.
        
        Parameters:
        -----------
        idx : int
            Index before the desired Node.

        Return: Node
        """
        # If index not in list's bound do nothing.
        if not self.checkIndexBounds(idx): return

        curr = self.head
        pre = None

        for _ in range(idx):
            pre = curr
            curr = curr.next

        return pre
    
    def addAtStart(self, value=None, node=None):
        """ Adds a given Node to the list if it's not None
            or creates one with the given value if this
            last one it's not None.

        Parameters:
        ----------
        value : object
            New value to be added to the list.
        
        node : Node
            Node to be added to the list.

        """
        tmp = None
        
        if value is not None:
            tmp = Node(value)
        elif node is not None:
            tmp = node

        if self.head is None:
            self.add(node=tmp)
            return
        
        tmp.next = self.head
        self.head = tmp
        self.length += 1
    
    def addAtIndex(self, idx, value=None, node=None):
        """ Adds at the given index idx of the list 
            a given Node  to the list if it's not 
            None or creates  one with the given value 
            if this last one it's not None. 
            
            Parameters:
            ----------
            idx : int
                Index where to add the new Node.
            
            value : object
                New value to be added to the list.

            node : Node
                Node to be added to the list.

            """
        # If index not in list's bound do nothing.
        if not self.checkIndexBounds(idx): return

        pre = self.getNodeBeforeIndex(idx)
        curr = pre.next
        if value is not None:
            n = Node(value)
            pre.next = n
            n.next = curr
        elif node is not None:
            pre.next = node
            node.next = curr
        self.length += 1
    
    def pop(self):
        """ Pops out the last element of the list. """
        pre = self.getNodeBeforeIndex(self.length - 1)
        curr = pre.next
        self.tail = pre
        pre.next = None
        del curr
        self.length -= 1
    
    def popFirst(self):
        """ Pops out the first element of the list. """
        node = self.head
        self.head = self.head.next
        del node
        self.length -= 1
    
    def popFromIndex(self, idx):
        """ Pops out the element at the given index idx. 
        
        Parameters:
        -----------
        idx : int
            Index of the element to be popped out.

        """
        # If index not in list's bound do nothing.
        if not self.checkIndexBounds(idx): return

        pre = self.getNodeBeforeIndex(idx)
        curr = pre.next
        pre.next = curr.next
        del curr
        self.length -= 1
        
if __name__ == '__main__':
    llist = LinkedList()

    for i in range(10): llist.add(i**2)
    llist.displayNodes()

    llist.addAtIndex(3, 77)
    llist.addAtStart(55)

    llist.displayNodes()
    llist.popFromIndex(2)
    llist.pop()

    llist.displayNodes()