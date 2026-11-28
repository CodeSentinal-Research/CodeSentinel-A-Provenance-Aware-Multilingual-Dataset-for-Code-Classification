#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_set<int> seen;
    for (int i = 0; i < n; i++) {
        if (seen.find(arr[i]) != seen.end()) {
            cout << arr[i] << endl;
            break;
        }
        seen.insert(arr[i]);
    }

    return 0;
}