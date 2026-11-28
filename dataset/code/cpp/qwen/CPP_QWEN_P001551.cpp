#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int maxLen = 0;
    long long currentSum = 0;
    int left = 0;
    
    for (int right = 0; right < n; ++right) {
        currentSum += nums[right];
        while (currentSum > k) {
            currentSum -= nums[left];
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    
    cout << maxLen << endl;
    return 0;
}
