#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int right = 0;
    for (int left = 0; left < n; left++) {
        if (arr[left] == 0) {
            continue;
        }
        while (right < n && arr[right] != 0) {
            right++;
        }
        if (right < n) {
            arr[left] *= 2;
            arr[right] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}