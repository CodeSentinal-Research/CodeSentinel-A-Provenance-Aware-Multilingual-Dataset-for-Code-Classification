#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int largestUniqueNumber(vector<int> arr) {
    unordered_set<int> s;
    for (int num : arr) {
        s.insert(num);
    }
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (s.count(arr[i]) == 1) {
            return arr[i];
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << largestUniqueNumber(arr);
    return 0;
}