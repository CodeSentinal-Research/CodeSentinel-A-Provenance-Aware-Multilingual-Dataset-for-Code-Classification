#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int maxLen = 1;
    int currLen = 1;
    
    for (int i = 1; i < n; ++i) {
        if ((nums[i] % 2) != (nums[i-1] % 2)) {
            currLen++;
        } else {
            currLen = 1;
        }
        maxLen = max(maxLen, currLen);
    }
    
    cout << maxLen << endl;
    return 0;
}
