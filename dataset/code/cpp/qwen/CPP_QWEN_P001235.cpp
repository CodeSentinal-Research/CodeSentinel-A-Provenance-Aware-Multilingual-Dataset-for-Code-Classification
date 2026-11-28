#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> jobs(n); // {profit, deadline}
    for (int i = 0; i < n; ++i) {
        cin >> jobs[i].second >> jobs[i].first;
    }
    
    sort(jobs.rbegin(), jobs.rend());
    
    int maxDeadline = 0;
    for (auto& j : jobs) maxDeadline = max(maxDeadline, j.second);
    
    vector<int> slot(maxDeadline + 1, -1);
    int totalProfit = 0;
    int jobCount = 0;
    
    for (auto& j : jobs) {
        int profit = j.first;
        int deadline = j.second;
        
        for (int k = deadline; k > 0; --k) {
            if (slot[k] == -1) {
                slot[k] = profit;
                totalProfit += profit;
                jobCount++;
                break;
            }
        }
    }
    
    cout << totalProfit << endl;
    return 0;
}
