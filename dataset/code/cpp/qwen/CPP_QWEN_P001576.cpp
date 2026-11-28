#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int count = 0;
    int zeros = 0;
    
    for (int i = 0; i < k; ++i) {
        if (nums[i] == 0) zeros++;
    }
    if (zeros > 0) count++;
    
    for (int i = k; i < n; ++i) {
        if (nums[i] == 0) zeros++;
        if (nums[i-k] == 0) zeros--;
        if (zeros > 0) count++;
    }
    
    cout << count << endl;
    return 0;
}
