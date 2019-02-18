#include <iostream>
#include <list>
#include <queue>

class Graph {
    private:
        // Num of vertices
        int V;

        // Pointer to an array 
        // containing adjacency list
        std::list<int>* adj; 

    public:
        Graph(int);

        void addEdge(int, int);

        // Prints BFS traversal from a given source
        // (Breadth-First Search)
        void BFS(int);
};

// Constructor
Graph::Graph(int V) {
    this->V = V;
    adj = new std::list<int>[V];
};

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v's list
};

void Graph::BFS(int s) {
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for(int i = 0; i < V; i++) visited[i] = false;

    // Create a queue for BFS
    std::queue<int> q;

    // Mark the current node as visited an push it
    // to the queue
    visited[s] = true;
    q.push(s);

    // Iterator will be used to get all
    // adjacent vertices of a vertex
    std::list<int>::iterator i;

    while(!q.empty()) {
        // Dequeue a vertex from a queue and print it
        s = q.front();
        std::cout << s << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued
        // vertex s. If an adjacent has not been visited,
        // then mark it visited and enqueue it.
        for(i = adj[s].begin(); i != adj[s].end(); ++i) {
            if(!visited[*i]) {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
};