#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }
    for (int i = 1; i <= n + 2; i++) {
        if (s.find(i) == s.end()) {
            cout << i;
            return 0;
        }
    }
    return 0;
}