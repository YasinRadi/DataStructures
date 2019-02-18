using System;
using System.Collections.Generic;
using System.Text;


/// <summary>
/// Depth-First Search implementation class.
/// </summary>
public class GraphDFS
{
    // Num of vertices
    private int numVertex;

    // Adjacency list
    private LinkedList<int>[] adj;

    // Constructor
    public GraphDFS(int n) {
        this.numVertex = n;
        this.adj = new LinkedList<int>[n];
        for (int i = 0; i < n; i++)
            this.adj[i] = new LinkedList<int>();
    }

    /// <summary>
    /// Recursive function to perform a DFS traversal.
    /// </summary>
    /// <param name="nodeIndex">Index of the node to start with.</param>
    /// <param name="visited">Array holding node visited status.</param>
    /// <param name="sb">StringBuilder to perform value printing.</param>
    private void DFSUtil(int nodeIndex, ref bool[] visited, StringBuilder sb) {
        // Mark current node as visited
        // Append it for printing
        visited[nodeIndex] = true;
        sb.Append(nodeIndex).Append(" ");

        // Recurr for all vertices
        // adjacent to this vertex
        foreach (int element in adj[nodeIndex])
            if (!visited[element])
                DFSUtil(element, ref visited, sb);
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
    /// Performs a Depth-First traversal to display
    /// all nodes contained in Graph.
    /// </summary>
    /// <param name="nodeIndex">Index of the node to start with.</param>
    public void DFS(int nodeIndex) {
        // Builder to display node content
        StringBuilder sb = new StringBuilder();

        // Mark all vertices as not visited
        bool[] visited = new bool[numVertex];
        for (int i = 0; i < numVertex; i++)
            visited[i] = false;

        // Call recursive helper to display DFS traversal.
        DFSUtil(nodeIndex, ref visited, sb);

        Console.WriteLine(sb.ToString());
    }
}
