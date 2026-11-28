#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<int> wave(2 * n);
    int left = 0, right = n - 1, k = 0;
    while (left < right) {
        wave[k++] = arr[left++];
        wave[k++] = arr[right--];
    }
    if (left == right) {
        wave[k] = arr[left];
    }

    printArray(wave);

    return 0;
}