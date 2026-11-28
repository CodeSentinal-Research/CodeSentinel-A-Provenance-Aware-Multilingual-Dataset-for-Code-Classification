#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<string> dict(m);
    for (int i = 0; i < m; i++) cin >> dict[i];
    vector<bool> bold(s.size(), false);
    for (const string& word : dict) {
        size_t pos = s.find(word);
        while (pos != string::npos) {
            for (int i = 0; i < word.size(); i++) bold[pos + i] = true;
            pos = s.find(word, pos + 1);
        }
    }
    string res = "";
    bool in_bold = false;
    for (int i = 0; i < s.size(); i++) {
        if (bold[i] && !in_bold) { res += "<b>"; in_bold = true; }
        else if (!bold[i] && in_bold) { res += "</b>"; in_bold = false; }
        res += s[i];
    }
    if (in_bold) res += "</b>";
    cout << res << endl;
    return 0;
}
