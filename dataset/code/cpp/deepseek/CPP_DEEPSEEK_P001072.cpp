Here's the C++ code to solve the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int src, dest;
};

class Graph {
private:
    int V, E;
    vector<Edge> edges;
public:
    Graph(int V, int E);
    void addEdge(int src, int dest);
    int countSC();
};

Graph::Graph(int V, int E) {
    this->V = V;
    this->E = E;
}

void Graph::addEdge(int src, int dest) {
    edges.push_back(Edge{src, dest});
}

int find(vector<int> parent, int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void Union(vector<int> &parent, int x, int y) {
    parent[x] = y;
}

int Graph::countSC() {
    vector<int> parent;
    parent.resize(V);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    for (int i = 0; i < E; i++) {
        int x = find(parent, edges[i].src);
        int y = find(parent, edges[i].dest);

        if (x != y)
            Union(parent, x, y);
    }

    int ans = 0;
    for (int i = 0; i < V; i++)
        if (parent[i] == i)
            ans++;

    return ans;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V, E);
    for (int i = 0; i < E; i++) {
        int src, dest;
        cout << "Enter source and destination: ";
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    cout << "Strongly Connected components count: " << g.countSC() << endl;

    return 0;
}

The code defines a class `Edge` to represent the edges of the graph. A class `Graph` is defined to represent the graph and contains methods to add edges and count strongly connected components.

The `find` function is used to find the parent of a node in the disjoint set.

The `Union` function is used to merge two disjoint sets.

The `countSC` function counts the number of strongly connected components in the graph. It first initializes the parent array, then it iterates over the edges and updates the parent array accordingly. Finally, it counts the number of parents that are not themselves a parent (i.e., it counts the number of roots in the parent array).

The main function reads the number of vertices and edges, creates a graph, and calls the `countSC` function to count the number of strongly connected components.