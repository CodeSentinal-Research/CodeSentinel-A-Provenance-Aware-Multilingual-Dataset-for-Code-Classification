#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int diff = arr[1] - arr[0];

    for(int i = 2; i < n; i++) {
        if(arr[i] - arr[i-1] != diff) {
            cout << "Cannot reconstruct the array.";
            return 0;
        }
    }

    for(int i = 0; i < n; i++) {
        arr[i] += diff;
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}