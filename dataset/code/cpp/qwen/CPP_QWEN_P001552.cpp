#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int minLen = INT_MAX;
    long long currentSum = 0;
    int left = 0;
    
    for (int right = 0; right < n; ++right) {
        currentSum += nums[right];
        while (currentSum > x) {
            minLen = min(minLen, right - left + 1);
            currentSum -= nums[left];
            left++;
        }
    }
    
    cout << (minLen == INT_MAX ? -1 : minLen) << endl;
    return 0;
}
