/*
 * Input:
 * The first line contains two integers N and M, representing the number of vertices and edges in a Directed Acyclic Graph (DAG).
 * The next M lines each contain two integers u and v, representing a directed edge from vertex u to vertex v.
 *
 * Output:
 * The total number of paths from all source nodes (nodes with an in-degree of 0) to all sink nodes (nodes with an out-degree of 0), modulo 1e9 + 7.
 *
 * Purpose:
 * This program counts the total number of distinct paths in a Directed Acyclic Graph (DAG) starting from any source node and ending at any sink node.
 *
 * Algorithm:
 * Topological Sort with Dynamic Programming.
 *
 * Brief Explanation:
 * The algorithm leverages the properties of a DAG to count paths efficiently.
 * 1.  **Graph Representation**: The DAG is stored using an adjacency list. The in-degree and out-degree of each vertex are also calculated.
 * 2.  **Identify Sources and Sinks**:
 *     - Source nodes are vertices with an in-degree of 0. These are the starting points of all paths.
 *     - Sink nodes are vertices with an out-degree of 0. These are the ending points of all paths.
 * 3.  **Dynamic Programming (`dp` array)**: A `dp` array is used where `dp[i]` stores the number of paths from any source node to vertex `i`.
 * 4.  **Initialization**:
 *     - The `dp` value for all source nodes is initialized to 1, as there is one way to reach a source from a source (the path of length 0).
 *     - A queue is initialized with all source nodes, which is the standard start for a topological sort (Kahn's algorithm).
 * 5.  **Topological Sort and Path Counting**:
 *     - The algorithm processes nodes in a topological order.
 *     - When a node `u` is processed, it iterates through its neighbors `v`.
 *     - For each neighbor `v`, the number of paths to `u` (`dp[u]`) is added to `dp[v]`. This is because any path to `u` can be extended to `v`.
 *     - The in-degree of `v` is decremented. If the in-degree becomes 0, `v` is added to the queue to be processed.
 * 6.  **Final Calculation**: After the topological sort is complete, the `dp` array contains the total number of paths from sources to each node. The final answer is the sum of `dp[u]` for all sink nodes `u`.
 */
#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1, vector<int>());
    vector<int> in_degree(N + 1, 0);
    vector<int> out_degree(N + 1, 0);
    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
        out_degree[u]++;
    }

    // find sources and sinks
    vector<int> sources, sinks;
    for (int u = 1; u <= N; u++){
        if (in_degree[u] == 0) sources.push_back(u);
        if (out_degree[u] == 0) sinks.push_back(u);
    }
    vector<ll> dp(N + 1, 0);
    for (auto u : sources) dp[u] = 1;

    queue<int> q;
    for (auto u : sources) q.push(u);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (auto &v : adj[u]){
            dp[v] = (dp[v] + dp[u]) % MOD;
            in_degree[v]--;
            if (in_degree[v] == 0) q.push(v);
        }
    }

    ll total = 0;
    for (auto u : sinks) total = (total + dp[u]) % MOD;
    cout << total << endl;
}