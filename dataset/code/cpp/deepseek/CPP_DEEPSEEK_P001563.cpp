Here is the C++ code for the given problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Limit;
    cin >> N >> Limit;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int start = 0, end = 0, maxLength = 0;
    while (end < N) {
        Limit -= arr[end];
        while (Limit < 0) {
            Limit += arr[start];
            start++;
        }
        maxLength = max(maxLength, end - start + 1);
        end++;
    }

    cout << maxLength;

    return 0;
}

This code first reads the size of the array and the limit from the input. Then it reads the elements of the array. The code then uses a sliding window approach to find the longest subarray with the absolute difference between the maximum and minimum elements not exceeding the limit. The maximum length is updated whenever a longer subarray is found.