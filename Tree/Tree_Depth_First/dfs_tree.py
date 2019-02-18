
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

class DFSTree:
    """ Depth-First Binary Search Tree implementation class. 
    
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

    def _postOrderHelper(self, node):
        """ Helper function for postOrder traversal. 

        Parameters:
        -----------
        node : Node
            Node root node of traversal.
        
        """
        if node is None:
            return
        
        # Go left first
        self._postOrderHelper(node.left)

        # Then go right
        self._postOrderHelper(node.right)

        # Finally into self
        print(node.data, end=' ')

    def _inOrderHelper(self, node):
        """ Helper function for inOrder traversal.
        
        Parameters:
        -----------
        node : Node
            Node whose content will be displayed.
        """
        if node is None:
            return
        
        # Go left first
        self._inOrderHelper(node.left)

        # Then into node
        print(node.data, end=' ')

        # And then right
        self._inOrderHelper(node.right)
    
    def _preOrderHelper(self, node):
        """ Helper function for preOrder traversal. 
        
        Parameters:
        -----------
        node : Node
            Node whose content will be displayed.

        """
        if node is None:
            return
        
        # Into node first
        print(node.data, end=' ')

        # Then left
        self._preOrderHelper(node.left)

        # Right last
        self._preOrderHelper(node.right)

    def postOrder(self):
        """ Given a bin tree, prints its nodes according
            to the "bottom-up" postorder traversal.
                (LEFT, RIGHT, ROOT) 
        """
        self._postOrderHelper(self.root)
        print()

    def inOrder(self):
        """ Given a bin tree, prints its nodes according
            to the "bottom-up" inorder traversal.
                (LEFT, ROOT, RIGHT)

        """
        self._inOrderHelper(self.root)
        print()

    def preOrder(self):
        """ Given a bin tree, prints its nodes according
            to the "bottom-up" preorder traversal.
                (ROOT, LEFT, RIGHT) 

        """
        self._preOrderHelper(self.root)
        print()


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