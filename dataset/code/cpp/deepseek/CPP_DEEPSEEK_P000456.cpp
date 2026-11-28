Here is the code:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, H;
    cin >> N >> H;

    vector<int> piles(N);
    for (int i = 0; i < N; i++) {
        cin >> piles[i];
    }

    int left = 1, right = H;
    while (left < right) {
        int mid = (left + right) / 2;
        if (mid > *max_element(piles.begin(), piles.end(), [&mid](int a, int b) {
            return a / mid > b / mid;
        })) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << right;

    return 0;
}

This code uses binary search to find the minimum eating speed. It starts with the minimum eating speed of 1 (`left = 1`), and ends with the maximum possible eating speed (`right = H`). For each mid point, it checks if the current mid point is greater than or equal to the maximum pile size divided by the current mid point. If it is, it updates the `right` to the current mid point. Otherwise, it updates the `left` to the current mid point plus 1. The loop continues until `left` equals `right`, and `right` is the minimum eating speed for Koko to finish all bananas within H hours.