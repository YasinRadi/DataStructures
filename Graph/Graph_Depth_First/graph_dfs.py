from collections import deque

class GraphDFS:
    """ Graph Depth-First Search implementation class.
    
    Attributes:
    -----------
    numVertex : int
        Number of contained vertex in Graph.
    
    adj : list
        List of adjacency deques.


    Parameters:
    -----------
    numV : int
        Number of vertex to be contained.

    """

    def __init__(self, numV):
        self.numVertex = numV
        self.adj = [deque() for _ in range(numV)]

    def DFSUtil(self, indexNode, visited):
        """ Recursive function used by DFS traversal.
        
        Parameters:
        -----------
        indexNode : int
            Starting node of the traversal.
        
        visited : list
            bool list that details if a given node has been
            visited already.
        
        """
        # Mark the current node as visited
        visited[indexNode] = True
        # And print it
        print(indexNode, end=' ')


        for element in self.adj[indexNode]:
            if not visited[element]:
                self.DFSUtil(element, visited)

    def addEdge(self, nodeIndex, nodeValue):
        """ Adds a new edge/relation to an existing node in the Graph.

        Parameters:
        -----------
        nodeIndex : int
            Index of the node to be related with.
        
        nodeValue : int
            Index of the node that is relating.
        
        """
        self.adj[nodeIndex].append(nodeValue)

    def DFS(self, initialNode):
        """ Traverses through all nodes displaying
            the relation order with initialNode.

        Parameters:
        -----------
        initialNode : int
            Node owner of the relations to be displayed.
        
        """
        # Mark all vertices as not visited
        visited = [False for _ in range(self.numVertex)]

        # Call the recursive helper function
        # to print DFS traversal.
        self.DFSUtil(initialNode, visited)
        print()
