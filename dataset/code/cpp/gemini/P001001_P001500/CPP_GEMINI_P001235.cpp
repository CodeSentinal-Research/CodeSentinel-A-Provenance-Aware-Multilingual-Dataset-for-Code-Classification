#include <iostream>
#include <vector>
#include <algorithm>

struct Job {
    int deadline, profit;
};

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<Job> jobs(n);
        int maxD = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> jobs[i].deadline;
            maxD = std::max(maxD, jobs[i].deadline);
        }
        for (int i = 0; i < n; i++) std::cin >> jobs[i].profit;

        std::sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            return a.profit > b.profit;
        });

        std::vector<int> slots(maxD + 1, -1);
        int count = 0, totalProfit = 0;

        for (const auto& jb : jobs) {
            for (int j = jb.deadline; j > 0; j--) {
                if (slots[j] == -1) {
                    slots[j] = jb.profit;
                    count++;
                    totalProfit += jb.profit;
                    break;
                }
            }
        }
        std::cout << count << " " << totalProfit << "\n";
    }
    return 0;
}