#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    while (q--) {
        int x;
        cin >> x;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) { found = true; break; }
        }
        cout << (found ? "Found" : "Not Found") << endl;
    }
    return 0;
}
