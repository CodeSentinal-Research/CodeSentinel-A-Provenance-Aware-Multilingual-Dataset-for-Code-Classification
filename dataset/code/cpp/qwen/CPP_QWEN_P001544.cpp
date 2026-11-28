#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    long long windowSum = 0;
    for (int i = 0; i < k; ++i) windowSum += nums[i];
    
    int count = 0;
    if (windowSum > x) count++;
    
    for (int i = k; i < n; ++i) {
        windowSum += nums[i] - nums[i-k];
        if (windowSum > x) count++;
    }
    
    cout << count << endl;
    return 0;
}
