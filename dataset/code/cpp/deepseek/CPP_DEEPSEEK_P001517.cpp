#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int minSum = arr[0] + arr[1];

    for (int i = 0; i < N - 1; i += 2) {
        int sum = arr[i] + arr[i + 1];
        if (sum < minSum) {
            minSum = sum;
        }
    }

    cout << minSum;

    return 0;
}