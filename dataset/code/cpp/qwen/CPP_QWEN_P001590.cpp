#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int n;
    long long budget;
    cin >> n >> budget;
    
    vector<long long> charge(n), run(n);
    for (int i = 0; i < n; ++i) cin >> charge[i];
    for (int i = 0; i < n; ++i) cin >> run[i];
    
    deque<int> maxChargeIdx;
    long long currentRunSum = 0;
    int left = 0;
    int maxRobots = 0;
    
    for (int right = 0; right < n; ++right) {
        while (!maxChargeIdx.empty() && charge[maxChargeIdx.back()] <= charge[right]) {
            maxChargeIdx.pop_back();
        }
        maxChargeIdx.push_back(right);
        
        currentRunSum += run[right];
        
        long long maxCharge = charge[maxChargeIdx.front()];
        long long totalCost = maxCharge + (right - left + 1) * currentRunSum;
        
        while (totalCost > budget) {
            currentRunSum -= run[left];
            if (maxChargeIdx.front() == left) maxChargeIdx.pop_front();
            left++;
            if (left <= right) {
                maxCharge = charge[maxChargeIdx.front()];
                totalCost = maxCharge + (right - left + 1) * currentRunSum;
            } else {
                totalCost = 0;
            }
        }
        
        maxRobots = max(maxRobots, right - left + 1);
    }
    
    cout << maxRobots << endl;
    return 0;
}
