Here is the C++ code that fulfills your requirements:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int prefixSum = 0;
    int maxPrefixSum = 0;
    for(int i=0; i<n; i++) {
        prefixSum += arr[i];
        if(prefixSum > 0) {
            maxPrefixSum++;
        }
    }

    cout << maxPrefixSum << endl;

    return 0;
}

In this code, we read the number of elements and the array from the standard input. We then iterate through the array, accumulating the prefix sum. If the prefix sum is positive, we increment the `maxPrefixSum`. The final result is the maximum number of prefixes that sum to positive.