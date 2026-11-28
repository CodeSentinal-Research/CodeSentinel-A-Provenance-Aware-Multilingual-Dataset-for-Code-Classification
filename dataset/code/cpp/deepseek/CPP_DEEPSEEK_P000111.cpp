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

    int second_largest = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] != arr[i+1]) {
            second_largest = max(second_largest, arr[i]);
        }
    }

    cout << second_largest << endl;

    return 0;
}