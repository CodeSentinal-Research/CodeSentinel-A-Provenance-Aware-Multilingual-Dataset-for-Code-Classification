#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int count = 0;
    long long windowSum = 0;
    
    for (int i = 0; i < k; ++i) windowSum += nums[i];
    if (windowSum % d == 0) count++;
    
    for (int i = k; i < n; ++i) {
        windowSum += nums[i] - nums[i-k];
        if (windowSum % d == 0) count++;
    }
    
    cout << count << endl;
    return 0;
}
