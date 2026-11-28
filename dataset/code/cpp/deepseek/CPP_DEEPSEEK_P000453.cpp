#include <iostream>
using namespace std;

int findFixedPoint(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] < mid) {
            start = mid + 1;
        } else if (arr[mid] > mid) {
            end = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = findFixedPoint(arr, n);

    if (result == -1) {
        cout << "No fixed point" << endl;
    } else {
        cout << "Fixed point is " << result << endl;
    }

    return 0;
}