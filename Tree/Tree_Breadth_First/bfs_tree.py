from collections import deque

class Node:
    """ Tree Node implementation. 
    
    Attributes:
    -----------

    left : Node
        Left child of the node.
    
    right : Node
        Right child of the node.
    
    Parameters:
    -----------
    data : int
        Data to be held by the node.
    
    """
    def __init__(self, data):
        self.data = data
        self.left : Node = None
        self.right : Node = None

class BFSTree:
    """ Breadth-First Binary Search Tree implementation class. 
    
    Attributes:
    -----------
    root : Node
        Root node of the tree.

    """
    def __init__(self):
        self.root : Node = None
    
    def _insertHelper(self, root, node):
        """ Performs a STD BST insert. 
        
        Parameters:
        ----------
        root : Node
            Root of the tree.
        
        node : Node
            Node to be inserted.
        
        Returns:
        --------
        The root of the tree or the same node if tree is empty. 
        
        """
        # If tree is empty, return new node
        if root is None:
            root = node
            return node
        
        # Otherwise, recurr down the tree
        if node.data < root.data:
            root.left = self._insertHelper(root.left, node)
        elif node.data > root.data:
            root.right = self._insertHelper(root.right, node)
        
        # Return root of the tree
        return root

    def _inorderHelper(self, node):
        """ Recursive helper function for inorder traversal.

        Parameters:
        -----------
        node : Node
            Node whose content will be displayed. 
            
        """
        if node is None:
            return
        
        self._inorderHelper(node.left)
        print(node.data, end=' ')
        self._inorderHelper(node.right)

    def _levelOrderHelper(self, node):
        """ Helper function for level order traversal.

        Parameters:
        -----------
        node : Node
            Starting node for traversal content display. 
            
        """
        if node is None:
            return
        
        q = deque()
        q.append(node)

        while len(q) > 0:
            tmpNode = q.popleft()
            print(tmpNode.data, end=' ')

            if tmpNode.left is not None:
                q.append(tmpNode.left)
            
            if tmpNode.right is not None:
                q.append(tmpNode.right)

    def insert(self, data):
        """ Inserts a new node into the tree.
        
        Parameters:
        -----------
        data : int
            Data to be inserted into the tree.
        
        """
        # Create node to be inserted.
        node = Node(data)

        # Perform a BST insert.
        # Update root if apliable
        self.root = self._insertHelper(self.root, node)
        
    def inorder(self):
        """ Inorder traversal tree content display. """
        self._inorderHelper(self.root)
        print()
    
    def levelOrder(self):
        """ Level Order traversal tree content display. """
        self._levelOrderHelper(self.root)
        print()