import java.util.Queue;
import java.util.LinkedList;

/**
 * Breadth-First Search implementation class.
 * @author Yasin Radi
 */
public class GraphBFS {

    // Num of vertices
    private int numVertex;

    // Adjacency list 
    private LinkedList<Integer>[] adj;

    // Constructor
    public GraphBFS(int n) {
        this.numVertex = n;
        this.adj = (LinkedList<Integer>[]) new LinkedList<?>[n];
        for(int i = 0; i < n; i++)
            this.adj[i] = new LinkedList<Integer>();
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
     * Performs a Breadth-First traversal to display
     * all nodes contained in Graph.
     * @param nodeIndex     int
    */
    public void BFS(int nodeIndex) {
        // Mark all the vertices as not visited
        boolean[] visited = new boolean[this.numVertex];
        for(int i = 0; i < this.numVertex; i++) 
            visited[i] = false;

        // Create a queue for BFS
        Queue<Integer> q = new LinkedList<>();

        // Mark the current node as visited and push it
        // to the queue
        visited[nodeIndex] = true;
        q.add(nodeIndex);

        // Builder to print result
        StringBuilder sb = new StringBuilder();

        while(!q.isEmpty()) {
            // Dequeue a vertex from the queue and print it
            int nodes = q.poll();
            sb.append(nodes).append(" ");

            // Get all adjacent vertices of the dequeued vertex.
            // If and adjacent has not been visited, then mark it
            // as visited and enqueue it.
            for(int element : this.adj[nodes]) {
                if(!visited[element]) {
                    visited[element] = true;
                    q.add(element);
                };
            };
        };

        System.out.println(sb.toString());
    };

    public static void main(String[] args) {
        GraphBFS g = new GraphBFS(4);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        System.out.println("BFS starting from v2: ");
        g.BFS(2);

        System.out.println("BFS starting from v0: ");
        g.BFS(0);

        System.out.println("BFS starting from v1: ");
        g.BFS(1);

        System.out.println("BFS starting from v3: ");
        g.BFS(3);
    };
};