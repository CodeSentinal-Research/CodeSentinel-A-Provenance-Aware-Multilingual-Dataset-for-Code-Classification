Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    int V;
    vector<int> *adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack) {
        visited[v] = true;

        for(int i = 0; i < adj[v].size(); i++) {
            int w = adj[v][i];
            if (!visited[w]) {
                topologicalSortUtil(w, visited, Stack);
            }
        }

        Stack.push(v);
    }

    void topologicalSort() {
        stack<int> Stack;

        bool *visited = new bool[V];
        for(int i = 0; i < V; i++) {
            visited[i] = false;
        }

        for(int i = 0; i < V; i++) {
            if (visited[i] == false) {
                topologicalSortUtil(i, visited, Stack);
            }
        }

        while(!Stack.empty()) {
            cout << Stack.top() << " ";
            Stack.pop();
        }
    }
};

int main() {
    int V, E, u, v;
    cin >> V >> E;

    Graph g(V);

    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.topologicalSort();

    return 0;
}
This program creates a directed graph and then performs a topological sort on it. The topological sort is a linear ordering of vertices such that for every directed edge UV in the digraph G, vertex U comes before vertex V in the ordering.