#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0, r = n - 1;
    while (l < r) {
        if (arr[l] + arr[r] > x) {
            r--;
        } else {
            l++;
            r--;
            int sum = arr[l] + arr[r];
            if (sum > x) {
                cout << l + 1 << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}