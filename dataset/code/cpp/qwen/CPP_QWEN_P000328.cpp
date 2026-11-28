#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> count;
    for (char c : s) count[c]++;
    for (int i = 0; i < s.size(); i++) {
        if (count[s[i]] == 1) { cout << i << endl; return 0; }
    }
    cout << -1 << endl;
    return 0;
}
