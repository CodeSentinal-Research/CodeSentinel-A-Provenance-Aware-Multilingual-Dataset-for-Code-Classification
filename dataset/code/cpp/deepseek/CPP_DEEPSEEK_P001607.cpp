#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int count0 = 0, count1 = 0, maxLen = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == 0) {
            count0++;
        } else {
            count1++;
        }

        if (count0 == count1 && i - count0 + 1 > maxLen) {
            maxLen = i - count0 + 1;
        }
    }

    cout << maxLen;
    return 0;
}
This C++ program reads an array of binary integers from the standard input, counts the number of zeros and ones, and keeps track of the longest subarray with equal number of zeros and ones. It then outputs the maximum length.