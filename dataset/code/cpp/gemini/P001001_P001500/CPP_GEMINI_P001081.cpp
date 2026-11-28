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
        bool ok = true;
        for (int d : deg) if (d % 2 != 0) { ok = false; break; }
        if (!ok) {
            std::cout << "NONE\n";
        } else {
            std::vector<bool> used(m, false);
            std::stack<int> st;
            std::vector<int> circuit;
            st.push(0);
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
                    circuit.push_back(st.top());
                    st.pop();
                }
            }
            std::reverse(circuit.begin(), circuit.end());
            for (size_t i = 0; i < circuit.size(); i++) {
                std::cout << circuit[i] << (i == circuit.size() - 1 ? "" : " ");
            }
            std::cout << "\n";
        }
    }
    return 0;
}