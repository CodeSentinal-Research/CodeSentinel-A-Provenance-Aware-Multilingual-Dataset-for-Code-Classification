#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int scheduleCourse(std::vector<std::vector<int>>& courses) {
        std::sort(courses.begin(), courses.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        std::priority_queue<int> pq;
        int time = 0;

        for (const auto& c : courses) {
            time += c[0];
            pq.push(c[0]);
            if (time > c[1]) {
                time -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};