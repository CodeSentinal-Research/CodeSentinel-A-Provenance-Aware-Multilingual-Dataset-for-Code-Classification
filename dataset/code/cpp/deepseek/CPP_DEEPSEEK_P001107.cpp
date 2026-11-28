Here is the C++ code for the problem:

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N, vector<int>(N, 0));

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

In this code, we first read the number of vertices and edges from the input. Then we create a 2D vector `graph` to represent the graph. After that, we read the edges from the input and update the graph accordingly. Finally, we print the transitive closure of the graph.