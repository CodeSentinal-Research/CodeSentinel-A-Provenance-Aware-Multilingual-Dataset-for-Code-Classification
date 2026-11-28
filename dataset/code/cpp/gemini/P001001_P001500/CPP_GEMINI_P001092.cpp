#include <vector>

class TreeAncestor {
    int LOG = 20;
    std::vector<std::vector<int>> up;
public:
    TreeAncestor(int n, std::vector<int>& parent) {
        up.assign(n, std::vector<int>(LOG, -1));
        for (int i = 0; i < n; i++) {
            up[i][0] = parent[i];
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (up[i][j - 1] != -1) {
                    up[i][j] = up[up[i][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < LOG; j++) {
            // If current bit is set, multiply base into result
            if ((k >> j) & 1) {
                node = up[node][j];
                if (node == -1) break;
            }
        }
        return node;
    }
};