#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int minLen = INT_MAX;
    int currentSum = 0;
    int left = 0;
    
    for (int right = 0; right < n; ++right) {
        currentSum += nums[right];
        while (currentSum >= target) {
            minLen = min(minLen, right - left + 1);
            currentSum -= nums[left];
            left++;
        }
    }
    
    cout << (minLen == INT_MAX ? 0 : minLen) << endl;
    return 0;
}
