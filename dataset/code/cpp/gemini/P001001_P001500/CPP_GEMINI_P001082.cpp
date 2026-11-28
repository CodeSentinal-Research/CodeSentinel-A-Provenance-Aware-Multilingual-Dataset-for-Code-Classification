#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<int> deg(n, 0);
        std::vector<std::pair<int, int>> edges(m);
        for (int i = 0; i < m; i++) {
            std::cin >> edges[i].first >> edges[i].second;
            deg[edges[i].first]++;
            deg[edges[i].second]++;
        }
        std::vector<int> odd;
        for (int i = 0; i < n; i++) {
            if (deg[i] % 2 != 0) odd.push_back(i);
        }
        if (odd.size() != 0 && odd.size() != 2) {
            std::cout << "NONE\n";
        } else {
            int start = odd.size() == 2 ? odd[0] : 0;
            std::vector<bool> used(m, false);
            std::stack<int> st;
            std::vector<int> path;
            st.push(start);
            while (!st.empty()) {
                int u = st.top();
                int eIdx = -1;
                for (int i = 0; i < m; i++) {
                    if (!used[i] && (edges[i].first == u || edges[i].second == u)) {
                        eIdx = i;
                        break;
                    }
                }
                if (eIdx != -1) {
                    used[eIdx] = true;
                    int next = (edges[eIdx].first == u) ? edges[eIdx].second : edges[eIdx].first;
                    st.push(next);
                } else {
                    path.push_back(st.top());
                    st.pop();
                }
            }
            std::reverse(path.begin(), path.end());
            for (size_t i = 0; i < path.size(); i++) {
                std::cout << path[i] << (i == path.size() - 1 ? "" : " ");
            }
            std::cout << "\n";
        }
    }
    return 0;
}