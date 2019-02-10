
class Node:
    """ LinkedList Node implementation class."""

    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next
    
class LinkedList:
    """ LinkedList implementation class."""

    def __init__(self):
        self.length = 0
        self.head : Node = None
        self.tail : Node = None
    
    def add(self, value=None, node=None):
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
        node = self.head
        while node is not None:
            print(node.data, end=' ')
            node = node.next
        print()
    
    def getNodeBeforeIndex(self, idx):
        curr = self.head
        pre = Node()

        for _ in range(idx):
            pre = curr
            curr = curr.next

        return pre
    
    def addAtStart(self, value):
        if self.head is None:
            self.add(value)
            return
        
        new = Node(value, self.head)
        self.head = new
        self.length += 1
    
    def addAtIndex(self, idx, value=None, node=None):
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
        pre = self.getNodeBeforeIndex(self.length - 1)
        curr = pre.next
        self.tail = pre
        pre.next = None
        del curr
        self.length -= 1
    
    def popFirst(self):
        node = self.head
        self.head = self.head.next
        del node
        self.length -= 1
    
    def popFromIndex(self, idx):
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