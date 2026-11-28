#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    if (s.size() != t.size()) {
        cout << "No" << endl;
        return 0;
    }

    unordered_map<char, char> smap;
    unordered_map<char, bool> used;
    for (int i = 0; i < s.size(); i++) {
        if (used.count(s[i])) {
            if (smap[s[i]] != t[i]) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            if (smap.count(t[i])) {
                cout << "No" << endl;
                return 0;
           
            }
            smap[s[i]] = t[i];
            used[s[i]] = true;
        }
    }

    cout << "Yes" << endl;
    return 0;
}