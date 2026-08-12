#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace std::chrono;

/**
 * @class Graph
 * @brief Represents an undirected graph using an adjacency list and
 *        provides DFS and BFS traversal methods.
 */
class Graph {
private:
    int V;                          ///< Number of vertices in the graph
    vector<vector<int>> adj;        ///< Adjacency list representation

    /**
     * @brief Recursive helper function used by DFS().
     * @param v       Current vertex being visited
     * @param visited Reference to the visited-tracking array
     */
    void DFSUtil(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";

        // Recur for all unvisited neighbors of the current vertex
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

public:
    /**
     * @brief Constructs a graph with a given number of vertices.
     * @param vertices Total number of vertices in the graph
     */
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    /**
     * @brief Adds an undirected edge between two vertices.
     * @param u First endpoint of the edge
     * @param v Second endpoint of the edge
     *
     * Note: To convert this into a directed graph, simply remove the
     * second push_back call below (adj[v].push_back(u)).
     */
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Remove this line for a directed graph
    }

    /**
     * @brief Performs a Depth-First Search starting from a given vertex
     *        and prints the traversal order.
     * @param start Starting vertex for the DFS traversal
     */
    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }

    /**
     * @brief Performs a Breadth-First Search starting from a given vertex
     *        and prints the traversal order.
     * @param start Starting vertex for the BFS traversal
     */
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            // Enqueue all unvisited neighbors of the current node
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int V, E;

    // ---- Input: graph size ----
    cout << "Enter number of vertices: ";
    cin >> V;
    Graph g(V);

    // ---- Input: edges ----
    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    // ---- Input: starting vertex ----
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    // ---- DFS traversal + timing ----
    auto startDFS = high_resolution_clock::now();
    cout << "\nDFS Traversal: ";
    g.DFS(start);
    auto endDFS = high_resolution_clock::now();
    auto dfsTime = duration_cast<nanoseconds>(endDFS - startDFS);

    // ---- BFS traversal + timing ----
    auto startBFS = high_resolution_clock::now();
    cout << "\n\nBFS Traversal: ";
    g.BFS(start);
    auto endBFS = high_resolution_clock::now();
    auto bfsTime = duration_cast<nanoseconds>(endBFS - startBFS);

    // ---- Results ----
    cout << "\n\nExecution Time:";
    cout << "\nDFS: " << dfsTime.count() << " ns";
    cout << "\nBFS: " << bfsTime.count() << " ns";

    return 0;
}
