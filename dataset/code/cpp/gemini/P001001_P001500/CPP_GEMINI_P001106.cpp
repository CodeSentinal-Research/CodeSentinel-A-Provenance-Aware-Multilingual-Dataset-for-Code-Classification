#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> inDeg(numCourses, 0);
        for (const auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            inDeg[p[0]]++;
        }
        std::queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0) q.push(i);
        }
        std::vector<int> order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                if (--inDeg[v] == 0) q.push(v);
            }
        }
        return (int)order.size() == numCourses ? order : std::vector<int>();
    }
};