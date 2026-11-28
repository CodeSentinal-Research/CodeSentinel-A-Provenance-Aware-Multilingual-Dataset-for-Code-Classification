#include <vector>
#include <algorithm>

struct Job {
    int id;
    int deadline;
    int profit;
};

class Solution {
public:
    std::vector<int> JobScheduling(Job arr[], int n) {
        std::vector<Job> jobs(arr, arr + n);
        std::sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            return a.profit > b.profit;
        });

        int maxD = 0;
        for (const auto& j : jobs) maxD = std::max(maxD, j.deadline);

        std::vector<int> slot(maxD + 1, -1);
        int count = 0, totalProfit = 0;

        for (const auto& j : jobs) {
            for (int d = j.deadline; d > 0; d--) {
                if (slot[d] == -1) {
                    slot[d] = j.id;
                    count++;
                    totalProfit += j.profit;
                    break;
                }
            }
        }
        return {count, totalProfit};
    }
};