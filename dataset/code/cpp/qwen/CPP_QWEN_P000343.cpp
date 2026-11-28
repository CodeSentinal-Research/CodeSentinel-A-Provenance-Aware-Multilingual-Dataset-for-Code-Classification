#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string w1, w2;
    cin >> w1 >> w2;
    unordered_map<char, int> c1, c2;
    for (char c : w1) c1[c]++;
    for (char c : w2) c2[c]++;
    bool ok = true;
    for (char c = 'a'; c <= 'z'; c++) {
        if (abs(c1[c] - c2[c]) > 3) { ok = false; break; }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
