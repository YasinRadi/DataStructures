import java.util.Queue;
import java.util.LinkedList;

/**
 * Depth-First Search implementation class.
 * @author Yasin Radi
 */
public class GraphDFS {

    // Num of vertices
    private int numVertex;

    // Adjacency list 
    private LinkedList<Integer>[] adj;

    // Constructor
    public GraphDFS(int n) {
        this.numVertex = n;
        this.adj = (LinkedList<Integer>[]) new LinkedList<?>[n];
        for(int i = 0; i < n; i++)
            this.adj[i] = new LinkedList<Integer>();
    };

    /**
     * Recursive function to perform a DFS traversal.
     * @param nodeIndex     int
     * @param visited       boolean
     * @param sb            StringBuilder
     */
    private void DFSUtil(int nodeIndex, boolean[] visited, StringBuilder sb) {
        // Mark the current node as visited
        // And append it for printing
        visited[nodeIndex] = true;
        sb.append(nodeIndex).append(' ');

        // Recurr for all the vertices
        // adjacent to this vertex
        for(int element : this.adj[nodeIndex])
            if(!visited[element]) 
                DFSUtil(element, visited, sb);
    };

    /**
     * Adds a new edge to the Graph.
     * @param nodeIndex     int
     * @param newNodeValue  int
     */
    public void addEdge(int nodeIndex, int newNodeValue) {
        this.adj[nodeIndex].add(newNodeValue);
    };

    /**
     * Performs a Depth-First traversal to display
     * all nodes contained in Graph.
     * @param nodeIndex     int
    */
    public void DFS(int nodeIndex) {
        // Builder to display nodes content
        StringBuilder sb = new StringBuilder();

        // Mark all the vertices as not visited
        boolean[] visited = new boolean[this.numVertex];
        for(int i = 0; i < this.numVertex; i++) 
            visited[i] = false;

        // Call the recursive helper method to
        // display DFS traversal.
        DFSUtil(nodeIndex, visited, sb);

        System.out.println(sb.toString());
    };

    public static void main(String[] args) {
        GraphDFS g = new GraphDFS(4);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        System.out.println("DFS starting from v2: ");
        g.DFS(2);

        System.out.println("DFS starting from v0: ");
        g.DFS(0);

        System.out.println("DFS starting from v1: ");
        g.DFS(1);

        System.out.println("DFS starting from v3: ");
        g.DFS(3);
    };
};