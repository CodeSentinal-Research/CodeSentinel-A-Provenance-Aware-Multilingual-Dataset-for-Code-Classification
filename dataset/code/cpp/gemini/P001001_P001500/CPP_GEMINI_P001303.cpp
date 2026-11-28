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
        int i = 0;

        for (int step = 0; step < k; step++) {
            while (i < n && projects[i].first <= w) {
                pq.push(projects[i++].second);
            }
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};