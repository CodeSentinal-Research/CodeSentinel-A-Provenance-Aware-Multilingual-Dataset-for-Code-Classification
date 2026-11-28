#include <iostream>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int start = 0, end = n - 1, result = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            result = mid;
            start = mid + 1;
        }
        else if (arr[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    cout << result;
    return 0;
}