#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            return binarySearch(arr, mid + 1, right, target);
        return binarySearch(arr, left, mid - 1, target);
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int target;
    cin >> target;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = binarySearch(arr, 0, n - 1, target);
    (result == -1) ? cout << -1 : cout << result;
    return 0;
}