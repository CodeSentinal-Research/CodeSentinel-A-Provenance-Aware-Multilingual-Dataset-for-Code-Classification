Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#define INF 999999999

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, INF));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u-1][v-1] = w;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

In the main function, we first read the number of vertices and edges from the input. Then, we initialize a 2D vector to store the distances between all pairs of vertices. We read the edges from the input and store the weights in the corresponding positions in the 2D vector.

We then use Floyd-Warshall's algorithm to compute the shortest distances. In each iteration of the algorithm, we update the shortest distance from one vertex to all other vertices. The algorithm is used to compute the shortest distances between all pairs of vertices.

Finally, we print out the shortest distances between all pairs of vertices.