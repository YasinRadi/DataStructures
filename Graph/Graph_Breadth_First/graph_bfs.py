from collections import deque

class GraphBFS:
    """ Graph Breadth-First Search implementation class.
    
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

    def BFS(self, initialNode):
        """ Traverses through all nodes displaying
            the relation order with initialNode.

        Parameters:
        -----------
        initialNode : int
            Node owner of the relations to be displayed.
        
        """
        # Mark all vertices as not visited
        visited = [False for _ in range(self.numVertex)]

        # Queue for BFS
        queue = deque()

        # Mark the current node as visited and push it
        # to the queue
        visited[initialNode] = True
        queue.append(initialNode)

        while len(queue) > 0:
            # Dequeue a vertex from queue and print it
            node = queue.popleft()
            print(node, end=' ')

            # Get all adjacent vertices of the dequeued 
            # element node. If and adjacent element has not
            # been visited, mark it as visited and enqueue it.
            for element in self.adj[node]:
                if not visited[element]:
                    visited[element] = True
                    queue.append(element)
        print()

if __name__ == '__main__':
    g = GraphBFS(4)
    g.addEdge(0, 1)
    g.addEdge(0, 2)
    g.addEdge(1, 2)
    g.addEdge(2, 0)
    g.addEdge(2, 3)
    g.addEdge(3, 3)

    print('BFS starting from v2: ')
    g.BFS(2)

    print('BFS starting from v0: ')
    g.BFS(0)

    print('BFS starting from v1: ')
    g.BFS(1)

    print('BFS starting from v3: ')
    g.BFS(3)