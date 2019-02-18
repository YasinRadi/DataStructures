from collections import deque
from enum import Enum

# Possible colors of Red Black Tree nodes.
COLOR = Enum('COLOR', 'RED BLACK')

class Node:
    """ Tree Node implementation class. 
    
    Attributes:
    -----------
    data : int
        Data held by the node.
    
    color : COLOR
        Color of the node.

    left : Node
        Left child of the node.
    
    right : Node
        Right child of the node.

    parent : Node
        Parent of the node.
    
    Parameters:
    -----------
    data : int
        Data to be held by the node.

    """
    def __init__(self, data):
        self.data = data
        self.color : COLOR = None
        self.left : Node = None
        self.right : Node = None
        self.parent : Node = None

class RedBlackTree:
    """ Red Black Tree implementation class. 
    
    Attributes:
    -----------
    root : Node
        Root node of the red black tree.

    """

    def __init__(self):
        self.root : Node = None
    
    def _BSTInsert(self, root : Node, node : Node):
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
        # If tree is empty return node
        if root is None:
            return node
        
        # Otherwise, recurr down the tree
        if node.data < root.data:
            root.left = self._BSTInsert(root.left, node)
            root.left.parent = root
        elif node.data > root.data:
            root.right = self._BSTInsert(root.right, node)
            root.right.parent = root
                
        # Return unchanged node
        return root
    
    def _inorderHelper(self, node : Node):
        """ Recursive helper function for inorder traversal.

        Parameters:
        -----------
        node : Node
            Node whose content will be displayed.
        
        """
        if node is None: return
        
        self._inorderHelper(node.left)
        print(node.data, end=' ')
        self._inorderHelper(node.right)
    
    def _levelOrderHelper(self, node : Node):
        """ Helper function for level order traversal.

        Parameters:
        -----------
        node : Node
            Starting node for traversal content display.
        
        """
        # Queue of nodes to be displayed
        q = deque()
        q.append(node)

        while len(q) > 0:
            tmpNode = q.popleft()
            print(tmpNode.data, end=' ')

            if tmpNode.left is not None:
                q.append(tmpNode.left)
            
            if tmpNode.right is not None:
                q.append(tmpNode.right)
    
    def rotateLeft(self, node : Node):
        """ Performs a subtree left rotation
            starting at the given node.
        
        Parameters:
        -----------
        node : Node
            Starting point of subtree rotation.
        
        """
        rightNode = node.right
        node.right = rightNode.left

        if node.right is not None:
            node.right.parent = node
        
        rightNode.parent = node.parent

        if node.parent is None:
            self.root = rightNode
        elif node == node.parent.left:
            node.parent.left = rightNode
        else:
            node.parent.right = rightNode
        
        rightNode.left = node
        node.parent = rightNode
    
    def rotateRight(self, node : Node):
        """ Performs a subtree right rotation
            starting at the given node.
        
        Parameters:
        -----------
        node : Node
            Starting point of subtree rotation.
        
        """
        leftNode = node.left
        node.left = leftNode.right

        if node.left is not None:
            node.left.parent = node
        
        leftNode.parent = node.parent
    
        if node.parent is None:
            self.root = leftNode
        elif node == node.parent.left:
            node.parent.left = leftNode
        else:
            node.parent.right = leftNode
        
        leftNode.right = node
        node.parent = leftNode

    def fixViolation(self, node : Node):
        """ Performs a fix of RB Tree properties
            to a subtree with root a the given node.
        
        Parameters:
        -----------
        node : Node
            Root of the subtree to fix.
        
        """
        parentNode = None
        grandParentNode = None

        while (node != self.root and node.color == COLOR.RED 
            and node.parent.color == COLOR.RED):
            parentNode = node.parent
            grandParentNode = parentNode.parent

            # CASE A:
            # Parent of node is left child of grand-parent of node
            if parentNode == grandParentNode.left:
                uncleNode = grandParentNode.right

                # CASE 1:
                # Uncle of node is also red
                # Only recoloring required
                if uncleNode is not None and uncleNode.color == COLOR.RED:
                    grandParentNode.color = COLOR.RED
                    parentNode.color = COLOR.BLACK
                    uncleNode.color = COLOR.BLACK
                else:
                    # CASE 2:
                    # node is right child
                    # Left-rotation required
                    if node == parentNode.right:
                        self.rotateLeft(parentNode)
                        node = parentNode
                        parentNode = node.parent

                    # CASE 3:
                    # node is left child
                    # Right-rotation required
                    self.rotateRight(grandParentNode)
                    tmpColor = parentNode.color
                    parentNode.color = grandParentNode.color
                    grandParentNode.color = tmpColor
                    node = parentNode
            
            # CASE B
            # Parent of node is right child        
            else:
                uncleNode = grandParentNode.left

                # CASE 1:
                # uncle is also red
                # Only recoloring required
                if uncleNode is not None and uncleNode.color == COLOR.RED:
                    grandParentNode.color = COLOR.RED
                    parentNode.color = COLOR.BLACK
                    uncleNode.color = COLOR.BLACK
                    node = grandParentNode
                else:
                    # CASE 2:
                    # node is left child
                    # Right-rotation requred
                    if node == parentNode.left:
                        self.rotateLeft(parentNode)
                        node = parentNode
                        parentNode = node.parent
                    
                    # CASE 3:
                    # node is right child
                    # Left-rotation required
                    self.rotateLeft(grandParentNode)
                    tmpColor = parentNode.color
                    parentNode.color = grandParentNode.color
                    grandParentNode.color = tmpColor
                    node = parentNode
        
        self.root.color = COLOR.BLACK
    
    def insert(self, data):
        """ Inserts a new node to tree.

        Parameters:
        -----------
        data : int
            Data to be inserted in a node and onto the tree.
        
        """
        node = Node(data)

        # Perform a normal BST insert
        self.root = self._BSTInsert(self.root, node)

        # Fix RB Tree violation
        self.fixViolation(node)
    
    def inorder(self):
        """ Inorder traversal tree content display. """
        self._inorderHelper(self.root)
        print()
    
    def levelOrder(self):
        """ Level Order traversal tree content display. """
        self._levelOrderHelper(self.root)
        print()