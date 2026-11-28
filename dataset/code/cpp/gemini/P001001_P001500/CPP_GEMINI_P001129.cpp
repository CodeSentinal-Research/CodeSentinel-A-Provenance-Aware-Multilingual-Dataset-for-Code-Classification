#include <vector>
#include <numeric>

class Solution {
    int findSet(std::vector<int>& parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = findSet(parent, parent[i]);
    }
public:
    int maxNumEdgesToRemove(int n, std::vector<std::vector<int>>& edges) {
        std::vector<int> parentA(n + 1), parentB(n + 1);
        std::iota(parentA.begin(), parentA.end(), 0);
        std::iota(parentB.begin(), parentB.end(), 0);

        int used = 0, edgesA = 0, edgesB = 0;

        for (const auto& e : edges) {
            if (e[0] == 3) {
                int rA1 = findSet(parentA, e[1]), rA2 = findSet(parentA, e[2]);
                int rB1 = findSet(parentB, e[1]), rB2 = findSet(parentB, e[2]);
                if (rA1 != rA2 || rB1 != rB2) {
                    parentA[rA1] = rA2;
                    parentB[rB1] = rB2;
                    used++;
                    edgesA++;
                    edgesB++;
                }
            }
        }

        for (const auto& e : edges) {
            if (e[0] == 1) {
                int r1 = findSet(parentA, e[1]), r2 = findSet(parentA, e[2]);
                if (r1 != r2) {
                    parentA[r1] = r2;
                    used++;
                    edgesA++;
                }
            } else if (e[0] == 2) {
                int r1 = findSet(parentB, e[1]), r2 = findSet(parentB, e[2]);
                if (r1 != r2) {
                    parentB[r1] = r2;
                    used++;
                    edgesB++;
                }
            }
        }

        return (edgesA == n - 1 && edgesB == n - 1) ? (int)edges.size() - used : -1;
    }
};