#include <iostream>
using namespace std;

int main() {
    int N, Q, L, R;
    cin >> N >> L >> R >> Q;

    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    double* sums = new double[N];
    for (int i = 0; i < N; i++) {
        sums[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        for (int j = max(i, 0); j <= min(i, R); j++) {
            sums[i] += arr[j];
        }
        sums[i] /= max(R - L + 1, 1);
    }

    for (int i = 0; i < Q; i++) {
        cin >> L >> R;
        cout << sums[R] - sums[L - 1] << endl;
    }

    delete[] arr;
    delete[] sums;

    return 0;
}