#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int> *adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    bool isSafe(int v, int color[], int c) {
        return !adj[v].empty() && adj[v].find(color[v]) != adj[v].end();
    }

    bool graphColoring(int v, int m) {
        int color[V] = {0};
        if (colorVertex(v, color, m) == 1)
            return true;

        return false;
    }

    int colorVertex(int v, int color[], int m) {
        if (v == V)
            return 1;

        for (int c = 1; c <= m; c++) {
            if (isSafe(v, color, c)) {
                color[v] = c;
                if (graphColoring(v + 1, m) == 1)
                    return 1;
                color[v] = 0;
            }
        }
        return 0;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    int m = 3;
    if (g.graphColoring(1, m) == 1)
        cout << "Solution exists";
    else
        cout << "Solution does not exist";

    return 0;
}
This code uses the concept of backtracking to solve the M-coloring problem. It checks if a vertex v can be colored with the first unused color c. If it can, it assigns the color to v and recursively tries to color the rest of the vertices. If it cannot find a color, it backtracks and unassigns the color from v and tries another color.