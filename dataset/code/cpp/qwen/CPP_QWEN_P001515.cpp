#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    long long count = 0;
    int currLen = 1;
    
    for (int i = 1; i < n; ++i) {
        if (nums[i] != nums[i-1]) {
            currLen++;
        } else {
            currLen = 1;
        }
        count += currLen;
    }
    
    // Subarrays of length 1 are always alternating? 
    // "Adjacent elements alternate". Length 1 has no adjacent pairs, so yes.
    // My logic adds 1 for single element, then extends if different.
    
    cout << count << endl;
    return 0;
}
