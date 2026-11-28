#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr1(n), arr2(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    return 0;
}