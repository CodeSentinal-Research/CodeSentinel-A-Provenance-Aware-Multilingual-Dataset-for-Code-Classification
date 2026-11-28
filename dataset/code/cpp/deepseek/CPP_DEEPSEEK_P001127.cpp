Here is the code:

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Provinces(int n, vector<vector<int>> adjacencyMatrix) {
    vector<bool> visited(n, false);
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            provinces++;
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int j = q.front();
                q.pop();

                for (int k = 0; k < n; k++) {
                    if (adjacencyMatrix[j][k] == 1 && !visited[k]) {
                        q.push(k);
                        visited[k] = true;
                    }
                }
            }
        }
    }

    return provinces;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adjacencyMatrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjacencyMatrix[i][j];
        }
    }

    cout << Provinces(n, adjacencyMatrix);

    return 0;
}

This code uses a depth-first search approach to solve the problem. It starts by creating an array of boolean values to keep track of visited nodes. For each unvisited node, it visits all the nodes in the same component (province) by pushing them into the queue and marking them as visited. The process is repeated until all the nodes have been visited.