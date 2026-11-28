#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int min_sum = arr[0] + arr[1];
    for (int i = 0; i < n - 1; i += 2) {
        int sum = arr[i] + arr[i + 1];
        if (sum < min_sum) {
            min_sum = sum;
        }
    }
    cout << min_sum;
    return 0;
}