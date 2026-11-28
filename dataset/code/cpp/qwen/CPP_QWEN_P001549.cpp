#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int count = 0;
    int currentPos = 0;
    
    for (int i = 0; i < k; ++i) {
        if (nums[i] > 0) currentPos++;
    }
    if (currentPos == k) count++;
    
    for (int i = k; i < n; ++i) {
        if (nums[i] > 0) currentPos++;
        if (nums[i-k] > 0) currentPos--;
        if (currentPos == k) count++;
    }
    
    cout << count << endl;
    return 0;
}
