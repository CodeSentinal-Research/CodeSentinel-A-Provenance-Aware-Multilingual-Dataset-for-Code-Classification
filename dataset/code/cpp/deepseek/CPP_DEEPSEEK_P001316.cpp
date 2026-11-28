Here is a C++ solution for the M-Coloring problem:

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int v, int graph[100][100], int color[], int c) {
    for (int i = 0; i < v; i++)
        if (graph[v][i] == 1 && c == color[i])
            return false;
    return true;
}

bool mcolor(int graph[100][100], int m, int v) {
    int color[100];
    for (int c = 0; c < m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graph[v][0] == 0)
                return true;
            if (mcolor(graph, m, v + 1) == 1)
                return true;
            color[v] = 0;
        }
    }
    return false;
}

int main() {
    int graph[100][100];
    int m, v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter number of colors: ";
    cin >> m;
    for (int i = 0; i < e; i++) {
        int u, w;
        cout << "Enter edge " << i + 1 << " (u,w): ";
        cin >> u >> w;
        graph[u][w] = graph[w][u] = 1;
    }
    if (mcolor(graph, m, 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

This code reads the number of vertices, edges, and colors from the standard input, and then creates a graph based on the input. It then uses the mcolor function to check whether a coloring is possible. The mcolor function iterates over all vertices and colors, and for each vertex and color, it checks if the current color is safe. If it is safe, it sets the color and recursively checks the rest of the graph. If a color is found to be safe, it returns true. If no safe color is found, it returns false.