#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    unordered_set<int> seen;
    for (int i = 0; i < n; i++) {
        if (seen.count(a[i])) { cout << a[i] << endl; return 0; }
        seen.insert(a[i]);
    }
    cout << -1 << endl;
    return 0;
}
