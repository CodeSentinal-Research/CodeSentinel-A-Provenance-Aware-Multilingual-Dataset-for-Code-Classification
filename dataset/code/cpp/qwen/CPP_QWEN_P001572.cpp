#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int count = 0;
    int currentSum = 0;
    
    for (int i = 0; i < k; ++i) currentSum += nums[i];
    if (currentSum % 2 == 0) count++;
    
    for (int i = k; i < n; ++i) {
        currentSum += nums[i] - nums[i-k];
        if (currentSum % 2 == 0) count++;
    }
    
    cout << count << endl;
    return 0;
}
