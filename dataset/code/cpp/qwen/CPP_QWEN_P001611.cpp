#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    deque<int> dq;
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i+1] = prefix[i] + nums[i];
    }
    
    int minLen = INT_MAX;
    
    for (int i = 0; i <= n; ++i) {
        while (!dq.empty() && prefix[i] < prefix[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
        
        // Check if we can form a valid subarray ending at i-1 starting from dq.front()
        // We want prefix[i] - prefix[j] >= k => prefix[j] <= prefix[i] - k
        // Since dq is increasing, we check from front
        
        while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
            minLen = min(minLen, i - dq.front());
            dq.pop_front();
        }
    }
    
    cout << (minLen == INT_MAX ? -1 : minLen) << endl;
    return 0;
}
