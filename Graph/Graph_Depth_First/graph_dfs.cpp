#include <iostream>
#include <list>

class Graph {
    private:
        // Num of vertices
        int V;

        /* Pointer to a list containing
           adjancency lists */
        std::list<int>* adj;

        // A recursive function used by DFS
        void DFSUtil(int, bool*);

    public:
        Graph(int);

        void addEdge(int, int);

        // DFS traversal of the vertices
        // reachable from a given v
        void DFS(int);
};

// Constructor
Graph::Graph(int V) {
    this->V = V;
    adj = new std::list<int>[V];
};

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v's list
};

void Graph::DFSUtil(int v, bool* visited) {
    // Mark the current node as visited
    // And print it
    visited[v] = true;
    std::cout << v << " ";

    // Recur for all the vertices
    // adjacent to this vertex
    std::list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i]) DFSUtil(*i, visited);
};

// DFS traversal of the vertices reachable from v
// It uses recursive DFSUtil
void Graph::DFS(int v) {
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for(int i = 0; i < V; i++) visited[i] = false;

    // Call the recursive helper function
    // to print DFS traversal.
    DFSUtil(v, visited);
};

int main(void) {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "DFS starting from v2: \n";
    g.DFS(2);

    std::cout << "\nDFS starting from v0: \n";
    g.DFS(0);

    std::cout << "\nDFS starting from v1: \n";
    g.DFS(1);

    std::cout << "\nDFS starting from v3: \n";
    g.DFS(3);

    return 0;
};