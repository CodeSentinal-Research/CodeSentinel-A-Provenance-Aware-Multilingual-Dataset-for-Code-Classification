#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int candidate = 0, count = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (count == 0) {
            candidate = x;
            count = 1;
        } else if (x == candidate) {
            count++;
        } else {
            count--;
        }
    }
    cout << candidate << "\n";
    return 0;
}
