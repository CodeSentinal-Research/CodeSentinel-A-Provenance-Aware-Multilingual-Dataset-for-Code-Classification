#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<std::vector<long long>> cap(n, std::vector<long long>(n, 0));
        for (int i = 0; i < m; i++) {
            int u, v;
            long long c;
            std::cin >> u >> v >> c;
            cap[u][v] += c;
        }
        int src, sink;
        std::cin >> src >> sink;
        long long flow = 0;

        while (true) {
            std::vector<int> parent(n, -1);
            parent[src] = -2;
            std::vector<long long> curCap(n, 0);
            curCap[src] = LLONG_MAX;
            std::queue<int> q;
            q.push(src);

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == sink) break;
                for (int v = 0; v < n; v++) {
                    if (parent[v] == -1 && cap[u][v] > 0) {
                        parent[v] = u;
                        curCap[v] = std::min(curCap[u], cap[u][v]);
                        q.push(v);
                    }
                }
            }
            if (parent[sink] == -1) break;
            long long aug = curCap[sink];
            flow += aug;
            int curr = sink;
            while (curr != src) {
                int p = parent[curr];
                cap[p][curr] -= aug;
                cap[curr][p] += aug;
                curr = p;
            }
        }
        std::cout << flow << "\n";
    }
    return 0;
}