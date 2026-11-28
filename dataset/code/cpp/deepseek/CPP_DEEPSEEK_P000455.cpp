#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;

    vector<int> weights(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }

    int low = 1;
    int high = *max_element(weights.begin(), weights.end());

    while (low < high) {
        int mid = (low + high) / 2;
        if (check(weights, N, D, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low;

    return 0;
}

bool check(vector<int>& weights, int N, int D, int capacity) {
    int current = 1;
    int packages = 0;

    for (int i = 0; i < N; i++) {
        if (weights[i] > capacity) {
            return false;
        }
        if (current <= capacity) {
            current += weights[i];
        } else {
            current = weights[i];
            packages++;
        }
        if (packages >= D) {
            return true;
        }
    }

    return false;
}
This C++ solution uses binary search to find the least weight capacity of a ship to ship all packages within D days. The binary search range is from 1 to the maximum package weight. For each middle capacity, it checks if it's possible to ship all packages within D days with that capacity. If it's possible, it updates the right end to mid; otherwise, it updates the left end to mid + 1. The time complexity of this algorithm is O(logN), where N is the number of packages.