Here is the complete C++ code for the problem:

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> safe_vertices;
vector<int> visited;
vector<int> order;
stack<int> s;

void dfs(int vertex, const vector<int> graph[]) {
    visited[vertex] = true;

    for (int i = 0; i < graph[vertex].size(); ++i) {
        int next_vertex = graph[vertex][i];

        if (!visited[next_vertex]) {
            dfs(next_vertex, graph);
        }
    }

    s.push(vertex);
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> graph[N];
    visited.resize(N, false);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            dfs(i, graph);
        }
    }

    while (!s.empty()) {
        int vertex = s.top();
        s.pop();

        if (order[vertex] == 0) {
            safe_vertices.push_back(vertex);
            order[vertex] = 1;
        }
    }

    sort(safe_vertices.begin(), safe_vertices.end());

    for (int i = 0; i < safe_vertices.size(); ++i) {
        cout << safe_vertices[i] << " ";
    }

    return 0;
}

This code first reads the number of vertices (N) and edges (M), and then reads the edges into the graph. It then performs a depth-first search (DFS) to find all the safe vertices. In the end, it prints out all the safe vertices in ascending order.