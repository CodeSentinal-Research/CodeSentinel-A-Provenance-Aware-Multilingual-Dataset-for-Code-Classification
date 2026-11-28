#include <iostream>
#include <vector>

using namespace std;

bool canBePartitioned(vector<int> &arr) {
    int n = arr.size();
    int count = 0;
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] - arr[i - 1] == arr[i + 1] - arr[i]) {
            count++;
        }
    }
    if (count == 0) {
        return false;
    }
    if (count == 1 && arr[0] - arr[1] != arr[n - 1] - arr[0]) {
        return false;
    }
    if (count == 1 && arr[0] - arr[1] == arr[n - 1] - arr[0]) {
        if (arr[1] - arr[0] < arr[n - 1] - arr[0]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (canBePartitioned(arr)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}