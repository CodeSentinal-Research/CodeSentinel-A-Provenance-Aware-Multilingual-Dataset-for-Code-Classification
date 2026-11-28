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
    string res = "";
    for (const string& word : dict) {
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            if (s[i] == word[j]) j++;
            i++;
        }
        if (j == word.size()) {
            if (word.size() > res.size() || (word.size() == res.size() && word < res)) {
                res = word;
            }
        }
    }
    cout << res << endl;
    return 0;
}
