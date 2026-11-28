#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    deque<int> maxQ, minQ;
    int minDiff = INT_MAX;
    
    for (int i = 0; i < n; ++i) {
        while (!maxQ.empty() && nums[maxQ.back()] <= nums[i]) maxQ.pop_back();
        maxQ.push_back(i);
        
        while (!minQ.empty() && nums[minQ.back()] >= nums[i]) minQ.pop_back();
        minQ.push_back(i);
        
        if (i >= k - 1) {
            int diff = nums[maxQ.front()] - nums[minQ.front()];
            minDiff = min(minDiff, diff);
            
            if (maxQ.front() == i - k + 1) maxQ.pop_front();
            if (minQ.front() == i - k + 1) minQ.pop_front();
        }
    }
    
    cout << minDiff << endl;
    return 0;
}
