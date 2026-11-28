Here is the code:

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Edge {
    int src, dest;
};

class Graph {
    int V;
    vector<Edge> edges;
    vector<int> tine;
    vector<bool> visited;

    void dfs(int v, int parent) {
        visited[v] = true;
        for(int i = 0; i < edges[v].size(); ++i) {
            Edge e = edges[v][i];
            if (!visited[e.dest]) {
                tine[e.dest]++;
                dfs(e.dest, v);
            } else if (e.dest != parent) {
                tine[e.dest]++;
           
            }
        }
    }

public:
    Graph(const vector<Edge> &edges, int V) : edges(edges), V(V) {
        visited.resize(V, false);
        tine.resize(V, 0);
    }

    void findArticulationPoints() {
        for(int i = 0; i < V; ++i) {
            if(!visited[i]) {
                dfs(i, -1);
            }
        }

        for(int i = 0; i < V; ++i) {
            if(tine[i] > 1) {
                cout << i << " ";
            }
        }
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges;
    for(int i = 0; i < E; ++i) {
        int src, dest;
        cin >> src >> dest;
        edges.push_back(Edge{src, dest});
    }

    Graph graph(edges, V);
    graph.findArticulationPoints();

    return 0;
}

This code first reads the number of vertices and edges, then it reads the edges and constructs a graph. The `findArticulationPoints` function is called to find the articulation points, and it prints them.