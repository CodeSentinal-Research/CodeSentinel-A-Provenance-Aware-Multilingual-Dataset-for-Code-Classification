#include <iostream>
#include <vector>

using namespace std;

int findSingle(vector<int> arr) {
    int res = 0;
    for (int i = 0; i < arr.size(); i++) {
        res ^= arr[i];
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << findSingle(arr);
    return 0;
}