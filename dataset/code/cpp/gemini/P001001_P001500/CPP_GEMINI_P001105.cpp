#include <vector>
#include <queue>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
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
        int count = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            count++;
            for (int v : adj[u]) {
                if (--inDeg[v] == 0) q.push(v);
            }
        }
        return count == numCourses;
    }
};