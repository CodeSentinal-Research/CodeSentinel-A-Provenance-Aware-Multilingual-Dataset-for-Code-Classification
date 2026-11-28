#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> s;
    bool found = false;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num < 0) {
            s.insert(-num);
        }
    }

    for (int i = n-1; i >= 0; i--) {
        if (s.find(n - i - 1) != s.end()) {
            found = true;
            cout << n - i - 1 << endl;
            break;
        }
    }

    if (!found) {
        cout << -1 << endl;
    }

    return 0;
}