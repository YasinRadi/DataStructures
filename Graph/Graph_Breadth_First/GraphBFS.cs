using System;
using System.Text;
using System.Collections.Generic;


/// <summary>
/// Breadth-First Search implementation class.
/// </summary>
public class GraphBFS
{

    // Num of vertices
    private int numVertex;

    // Adjacency list
    private LinkedList<int>[] adj;

    // Constructor
    public GraphBFS(int n) {
        this.numVertex = n;
        this.adj = new LinkedList<int>[n];
        for (int i = 0; i < n; i++)
            this.adj[i] = new LinkedList<int>();
    }

    /// <summary>
    /// Adds an edge to the graph.
    /// </summary>
    /// <param name="nodeIndex"> Index of node to add.</param>
    /// <param name="newNodeValue"> Value of the node being added.
    public void AddEdge(int nodeIndex, int newNodeValue) {
        adj[nodeIndex].AddLast(newNodeValue);
    }

    /// <summary>
    /// Performs a Breadth-First traversal to display
    /// all nodes contained in Graph.
    /// </summary>
    /// <param name="nodeIndex"> Index of node to start the BFS.</param>
    public void BFS(int nodeIndex) {
        // Mark all the vertices as not visited
        bool[] visited = new bool[numVertex];
        for (int i = 0; i < numVertex; i++)
            visited[i] = false;
        
        // Create a queue for BFS
        Queue<int> q = new Queue<int>();

        // Mark current node as visited and push it
        // to the queue
        visited[nodeIndex] = true;
        q.Enqueue(nodeIndex);

        // Builder to print result
        StringBuilder sb = new StringBuilder();

        while (q.Count > 0) {
            // Dequeues a vertex from the queue and prints it
            int node = q.Dequeue();
            sb.Append(node).Append(" ");

            /*
                Get all adjacent vertices of the dequeued vertex.
                If an adjacent has not been visited, mark it as 
                visited and enqueue it.
             */
             foreach (int element in adj[node]) {
                 if (!visited[element]) {
                     visited[element] = true;
                     q.Enqueue(element);
                 }
             }
        }

        Console.WriteLine(sb.ToString());
    }
}