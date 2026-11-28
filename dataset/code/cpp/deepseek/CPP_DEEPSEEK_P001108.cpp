Here is the C++ code to solve the problem:

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = make_pair(u, v);
    }

    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        bool found = false;
        for (int j = 0; j < M; j++) {
            if ((edges[j].first == u && edges[j].second == v) || (edges[j].first == v && edges[j].second == u)) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

In this code, we first read the number of vertices, edges, and queries. Then we read the edges. Finally, for each query, we check if there exists a path from the source to the destination.