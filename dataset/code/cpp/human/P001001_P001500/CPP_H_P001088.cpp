#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <utility>   // for std::pair

class Graph {
private:
    int V;                                               // number of vertices
    std::vector<std::vector<int>> adj;                   // unweighted adjacency list
    std::vector<std::vector<std::pair<int, int>>> weightedAdj;  // weighted adjacency list

    // Recursive DFS helper
    void dft(int v, std::vector<bool>& visited) {
        visited[v] = true;
        std::cout << v << " ";
        for (int u : adj[v]) {
            if (!visited[u]) {
                dft(u, visited);
            }
        }
    }

    // Helper to find the smallest unchecked vertex for Dijkstra
    int findSmallestUnchecked(const std::vector<bool>& toBeChecked,
                              const std::vector<int>& currDist) {
        int bestVertex = -1;
        int bestDistance = std::numeric_limits<int>::max();
        for (int i = 0; i < V; i++) {
            if (toBeChecked[i] && currDist[i] < bestDistance) {
                bestDistance = currDist[i];
                bestVertex = i;
            }
        }
        return bestVertex;
    }

public:
    // Store last Dijkstra results for path reconstruction
    std::vector<int> lastPredecessor;
    std::vector<int> lastDistances;

    // Constructor
    Graph(int vertices) : V(vertices), adj(vertices), weightedAdj(vertices) {}

    // ---------- Unweighted graph methods ----------
    void addEdge(int from, int to) {
        adj[from].push_back(to);
    }

    void addUndirectedEdge(int v1, int v2) {
        addEdge(v1, v2);
        addEdge(v2, v1);
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            std::cout << i << ": ";
            for (int neighbour : adj[i]) {
                std::cout << neighbour << " ";
            }
            std::cout << "\n";
        }
    }

    // ---------- Weighted graph methods ----------
    void addWeightedEdge(int from, int to, int weight) {
        weightedAdj[from].push_back({to, weight});
    }

    void addUndirectedWeightedEdge(int v1, int v2, int weight) {
        addWeightedEdge(v1, v2, weight);
        addWeightedEdge(v2, v1, weight);
    }

    void printWeightedGraph() {
        for (int i = 0; i < V; i++) {
            std::cout << i << ": ";
            for (auto edge : weightedAdj[i]) {
                std::cout << "(" << edge.first << ", " << edge.second << ") ";
            }
            std::cout << "\n";
        }
    }

    // ---------- Traversals ----------
    void depthFirstTraversal(int start) {
        std::vector<bool> visited(V, false);
        dft(start, visited);
    }

    void breadthFirstSearch(int start) {
        std::vector<bool> visited(V, false);
        std::queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            std::cout << curr << " ";
            for (int w : adj[curr]) {
                if (!visited[w]) {
                    visited[w] = true;
                    q.push(w);
                }
            }
        }
    }

    void iterativeDFS(int start) {
        std::vector<bool> visited(V, false);
        std::stack<int> st;
        st.push(start);

        while (!st.empty()) {
            int v = st.top();
            st.pop();
            if (!visited[v]) {
                visited[v] = true;
                std::cout << v << " ";
                // Push neighbours in reverse order to preserve ascending DFS order
                for (int i = adj[v].size() - 1; i >= 0; i--) {
                    int u = adj[v][i];
                    if (!visited[u]) {
                        st.push(u);
                    }
                }
            }
        }
    }

    // ---------- Dijkstra's algorithm (array version O(V^2)) ----------
    void dijkstra(int start) {
        std::vector<bool> toBeChecked(V, true);
        std::vector<int> currDist(V, std::numeric_limits<int>::max());
        std::vector<int> predecessor(V, -1);

        currDist[start] = 0;

        for (int count = 0; count < V; count++) {
            int v = findSmallestUnchecked(toBeChecked, currDist);
            if (v == -1) {
                break;   // all remaining vertices are unreachable
            }

            toBeChecked[v] = false;

            for (auto edge : weightedAdj[v]) {
                int u = edge.first;
                int weight = edge.second;

                if (toBeChecked[u] && currDist[v] != std::numeric_limits<int>::max()) {
                    int newDistance = currDist[v] + weight;
                    if (newDistance < currDist[u]) {
                        currDist[u] = newDistance;
                        predecessor[u] = v;
                    }
                }
            }
        }

        // Store results for later path reconstruction
        lastPredecessor = predecessor;
        lastDistances = currDist;

        // Print distances and predecessor array
        std::cout << "Shortest distances from vertex " << start << ":\n";
        for (int i = 0; i < V; i++) {
            std::cout << "  to " << i << ": ";
            if (currDist[i] == std::numeric_limits<int>::max()) {
                std::cout << "unreachable";
            } else {
                std::cout << currDist[i];
            }
            std::cout << "\n";
        }

        std::cout << "Predecessor array:\n";
        for (int i = 0; i < V; i++) {
            std::cout << "  predecessor[" << i << "] = " << predecessor[i] << "\n";
        }
    }

    // ---------- Path reconstruction ----------
    void printPath(int target, const std::vector<int>& predecessor) {
        std::stack<int> path;
        int current = target;
        while (current != -1) {
            path.push(current);
            current = predecessor[current];
        }

        std::cout << "Path to " << target << ": ";
        while (!path.empty()) {
            std::cout << path.top() << " ";
            path.pop();
        }
        std::cout << "\n";
    }

    // ---------- Sum of adjacent vertex labels (vector version) ----------
    int sumAdjacentLabels(int vertex) {
        int sum = 0;
        for (int neighbour : adj[vertex]) {
            sum += neighbour;
        }
        return sum;
    }
};

// ---------- Knight graph builder (standalone function) ----------
Graph buildKnightGraph(int rows, int cols) {
    Graph graph(rows * cols);
    int dr[] = { 2,  2, -2, -2,  1,  1, -1, -1 };
    int dc[] = { 1, -1,  1, -1,  2, -2,  2, -2 };

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int from = r * cols + c;
            for (int k = 0; k < 8; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int to = nr * cols + nc;
                    graph.addUndirectedEdge(from, to);
                }
            }
        }
    }
    return graph;
}

// ---------- Main with comprehensive tests ----------
int main() {
    // Test unweighted graph and traversals
    Graph g(5);
    g.addUndirectedEdge(0, 1);
    g.addUndirectedEdge(0, 2);
    g.addUndirectedEdge(1, 3);
    g.addUndirectedEdge(2, 4);

    std::cout << "=== Unweighted graph (adjacency list) ===\n";
    g.printGraph();

    std::cout << "\n--- DFS (recursive) from 0 ---\n";
    g.depthFirstTraversal(0);
    std::cout << "\n\n--- BFS from 0 ---\n";
    g.breadthFirstSearch(0);
    std::cout << "\n\n--- Iterative DFS from 0 ---\n";
    g.iterativeDFS(0);
    std::cout << "\n";

    // Test weighted graph and Dijkstra
    Graph wg(5);
    wg.addWeightedEdge(0, 1, 4);
    wg.addWeightedEdge(0, 2, 1);
    wg.addWeightedEdge(2, 1, 2);
    wg.addWeightedEdge(1, 3, 1);
    wg.addWeightedEdge(2, 3, 5);
    wg.addWeightedEdge(3, 4, 3);

    std::cout << "\n=== Weighted graph (adjacency list) ===\n";
    wg.printWeightedGraph();

    std::cout << "\n--- Dijkstra from 0 ---\n";
    wg.dijkstra(0);

    std::cout << "\n--- Path to vertex 4 ---\n";
    wg.printPath(4, wg.lastPredecessor);

    // Test sum of adjacent labels
    std::cout << "\n=== Sum adjacent labels ===\n";
    std::cout << "Sum of neighbours of vertex 0 in unweighted graph: "
              << g.sumAdjacentLabels(0) << "\n";

    // Test knight graph
    std::cout << "\n=== Knight graph (3x4 board) ===\n";
    Graph knight = buildKnightGraph(3, 4);
    knight.printGraph();

    std::cout << "\n--- BFS on knight graph from square 0 (a) ---\n";
    knight.breadthFirstSearch(0);
    std::cout << "\n";

    return 0;
}