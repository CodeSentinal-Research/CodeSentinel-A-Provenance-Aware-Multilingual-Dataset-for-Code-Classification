#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    if (s.size() != t.size()) {
        cout << "No" << endl;
        return 0;
    }
    unordered_map<char, char> map_s, map_t;
    for (int i = 0; i < s.size(); i++) {
        if (map_s.count(s[i]) && map_s[s[i]] != t[i]) { cout << "No" << endl; return 0; }
        if (map_t.count(t[i]) && map_t[t[i]] != s[i]) { cout << "No" << endl; return 0; }
        map_s[s[i]] = t[i];
        map_t[t[i]] = s[i];
    }
    cout << "Yes" << endl;
    return 0;
}
