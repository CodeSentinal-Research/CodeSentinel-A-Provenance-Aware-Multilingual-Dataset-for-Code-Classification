#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
        int n = profits.size();
        std::vector<std::pair<int, int>> projects(n);
        for (int i = 0; i < n; i++) {
            projects[i] = {capital[i], profits[i]};
        }
        std::sort(projects.begin(), projects.end());
        std::priority_queue<int> pq;
        int idx = 0;
        for (int i = 0; i < k; i++) {
            while (idx < n && projects[idx].first <= w) {
                pq.push(projects[idx].second);
                idx++;
            }
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};