Here is the C++ code for the problem:

#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int mid, int stalls[], int n, int cows) {
    int lastCow = stalls[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastCow >= mid) {
            lastCow = stalls[i];
            cnt++;
            if (cnt == cows) {
                return true;
            }
        }
    }
    return false;
}

int aggresiveCows(int stalls[], int n, int k) {
    sort(stalls, stalls + n);
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    while (low < high) {
        int mid = (low + high) / 2;
        if (isPossible(mid, stalls, n, k)) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return high;
}

int main() {
    int stalls[] = {1, 2, 3, 4, 8, 10};
    int n = sizeof(stalls) / sizeof(stalls[0]);
    int k = 3;
    cout << aggresiveCows(stalls, n, k) << endl;
    return 0;
}

This code first sorts the stalls array. Then it uses a binary search to find the maximum distance. The binary search is done in such a way that if the distance is possible, then `low` is moved to `mid + 1`, otherwise `high` is reduced to `mid`. The search continues until `low` is less than `high`. The `high` value at the end of the loop is the maximum possible minimum distance.