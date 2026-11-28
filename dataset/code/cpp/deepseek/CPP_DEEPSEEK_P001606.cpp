Here is the C++ solution for the given problem:

#include <iostream>
#include <vector>

using namespace std;

int countSubarrays(vector<int>& arr) {
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        int zeroCount = 0, oneCount = 0;
        for (int j = i; j < n; j++) {
            if (arr[j] == 0) zeroCount++;
            else oneCount++;

            if (zeroCount == oneCount) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << countSubarrays(arr) << endl;

    return 0;
}
This C++ code defines a function `countSubarrays` that calculates the number of subarrays containing an equal number of 0s and 1s. In this function, we iterate through the array and for each index, we count the number of 0s and 1s from that index onwards. If the count of 0s and 1s is the same, we increment the count. At the end of the function, we return the count.

In the `main` function, we first read the number of elements in the array and then read the array itself. The function `countSubarrays` is then called with the array as its argument and the result is printed out.