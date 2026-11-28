#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int maxNeg = 0;
    int currentNeg = 0;
    
    for (int i = 0; i < k; ++i) {
        if (nums[i] < 0) currentNeg++;
    }
    maxNeg = currentNeg;
    
    for (int i = k; i < n; ++i) {
        if (nums[i] < 0) currentNeg++;
        if (nums[i-k] < 0) currentNeg--;
        maxNeg = max(maxNeg, currentNeg);
    }
    
    cout << maxNeg << endl;
    return 0;
}
