#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int prefixSum = 0;
    int minPrefixSum = -1000000000; 
    int maxPrefixSum = 0;
    int longestNegativePrefixLength = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum < minPrefixSum) {
            minPrefixSum = prefixSum;
            longestNegativePrefixLength = i + 1; 
        } else if (prefixSum > maxPrefixSum) {
            maxPrefixSum = prefixSum;
        }
    }

    if (longestNegativePrefixLength == 0) {
        cout << 0 << endl;
    } else {
        cout << longestNegativePrefixLength << endl;
    }

    return 0;
}
This code reads the number of elements followed by the integers, calculates the sum of prefixes, and checks if the current sum is smaller or larger than the previous minimum and maximum sums. If it's smaller, it updates the minimum sum and the length of the prefix. If it's larger, it updates the maximum sum. After processing all elements, it prints out the length of the longest prefix whose sum is less than zero.