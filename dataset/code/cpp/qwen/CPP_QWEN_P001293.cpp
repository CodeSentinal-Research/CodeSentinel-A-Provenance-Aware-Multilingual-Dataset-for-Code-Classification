#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
    
    for (int i = 0; i < k; ++i) {
        int minVal = minHeap.top(); minHeap.pop();
        minVal++;
        minHeap.push(minVal);
    }
    
    long long product = 1;
    while (!minHeap.empty()) {
        product = (product * minHeap.top()) % MOD;
        minHeap.pop();
    }
    
    cout << product << endl;
    return 0;
}
