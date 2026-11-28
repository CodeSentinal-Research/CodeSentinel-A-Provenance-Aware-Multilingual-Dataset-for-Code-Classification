#include <iostream>
using namespace std;

int main() {
    int S, N, M;
    cin >> S >> N >> M;

    if (N > M || M * S < N) {
        cout << -1;
        return 0;
    }

    int start = N;
    int end = M * S;
    int purchase = 0;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        int need = mid;
        int days = 0;
        while (need > 0) {
            days++;
            need -= N;
        }

        if (days > S) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }

        purchase = mid;
    }

    cout << purchase;

    return 0;
}
This code works by binary search on the range of possible values of purchase days. For each mid point, it calculates the number of days needed to reach the maximum units of food. If the number of days exceeded the maximum number of days, it means the units of food cannot be reached within the maximum days, so the minimum number of days is increased by 1 (mid + 1). Otherwise, the minimum number of days is set to mid. At the end of the binary search, the final minimum number of days will be the answer.