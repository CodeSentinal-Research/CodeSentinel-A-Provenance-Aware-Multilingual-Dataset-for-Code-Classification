Here is the code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMedian(vector<int>& arr1, vector<int>& arr2) {
    vector<int> mergedArray;

    merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(mergedArray));

    int size = mergedArray.size();

    if (size % 2 == 0) {
        return (mergedArray[size / 2 - 1] + mergedArray[size / 2]) / 2.0;
    } else {
        return mergedArray[size / 2];
    }
}

int main() {
    int m, n;

    cin >> m >> n;

    vector<int> arr1(m), arr2(n);

    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    cout << findMedian(arr1, arr2);

    return 0;
}

In this code, the `findMedian` function merges the two sorted arrays and finds the median. The `main` function reads the sizes of the arrays and the arrays themselves, then calls the `findMedian` function to find and print the median of the two arrays.