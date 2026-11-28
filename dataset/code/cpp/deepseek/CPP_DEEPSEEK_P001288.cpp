#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int originalSum = 0;
    for (int i = 0; i < n; i++) {
        originalSum += arr[i];
    }

    while (k > 0) {
        int maxIndex = max_element(arr.begin(), arr.end()) - arr.begin();
        if (arr[maxIndex] < 0) {
            arr[maxIndex] = -arr[maxIndex];
            k--;
        } else {
            break;
        }
    }

    int modifiedSum = 0;
    for (int i = 0; i < n; i++) {
        modifiedSum += arr[i];
    }

    cout << max(originalSum, modifiedSum);

    return 0;
}