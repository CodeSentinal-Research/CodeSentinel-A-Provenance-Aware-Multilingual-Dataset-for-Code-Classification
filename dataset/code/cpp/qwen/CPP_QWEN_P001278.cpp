#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());
    
    int chunks = 0;
    long long sumOriginal = 0, sumSorted = 0;
    
    for (int i = 0; i < n; ++i) {
        sumOriginal += nums[i];
        sumSorted += sortedNums[i];
        if (sumOriginal == sumSorted) {
            chunks++;
        }
    }
    
    cout << chunks << endl;
    return 0;
}
