Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, pair<int, int>>> roads(M);
    vector<int> parent(N + 1);
    
    for (int i = 0; i < M; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        roads[i] = make_pair(cost, make_pair(u, v));
    }
    
    sort(roads.begin(), roads.end());
    
    int cost = 0;
    for (int i = 0; i < M; i++) {
        int u = roads[i].second.first;
        int v = roads[i].second.second;
        int cost = roads[i].first;
        
        if (find_parent(u) != find_parent(v)) {
            join_sets(u, v);
            cost += cost;
        }
    }
    
    if (is_connected()) {
        cout << cost << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}

int find_parent(int node) {
    if (parent[node] == node) return node;
    return parent[node] = find_parent(parent[node]);
}

void join_sets(int node1, int node2) {
    node1 = find_parent(node1);
    node2 = find_parent(node2);
    
    if (node1 != node2) {
        parent[node2] = node1;
    }
}

bool is_connected() {
    int root = 0;
    for (int i = 1; i <= N; i++) {
        root = find_parent(i);
        if (parent[i] != root) {
            return false;
        }
    }
    return true;
}

This code first takes the input for the number of cities `N` and roads `M`. It then takes the costs of the roads and stores them in a pair of cost and pairs of cities as the road. The road pairs are sorted in increasing order of costs.

In the main function, we iterate over the roads and if the cities that the road connects do not have the same parent, we join them into a set. The cost of the road is added to the total cost. If the graph is connected, then the total cost is printed out, otherwise -1 is printed.

The `find_parent` function is used to find the parent of a node, and the `join_sets` function is used to join two sets. The `is_connected` function is used to check if all nodes have the same parent.