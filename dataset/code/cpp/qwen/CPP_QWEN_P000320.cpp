#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    char c;
    cin >> s >> c;
    int n = s.size();
    vector<int> res(n, 0);
    int last = -10000;
    for (int i = 0; i < n; i++) {
        if (s[i] == c) last = i;
        res[i] = i - last;
    }
    last = 10000;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == c) last = i;
        res[i] = min(res[i], last - i);
    }
    for (int i = 0; i < n; i++) cout << res[i] << (i == n - 1 ? "" : " ");
    cout << endl;
    return 0;
}
