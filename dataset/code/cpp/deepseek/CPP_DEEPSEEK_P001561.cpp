#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    if (words.empty()) return res;

    int len = words[0].size();
    unordered_map<string, int> freq;

    for (const auto& word : words) {
        freq[word]++;
    }

    for (int i = 0; i <= s.size() - len * words.size(); i++) {
        unordered_map<string, int> seen;
        int j = 0;

        for (int k = i; k < s.size() - len + 1; k += len) {
            string str = s.substr(k, len);

            if (seen[str] < freq[str]) {
                seen[str]++;
                j++;
            } else {
                break;
            }
        }

        if (j == words.size()) {
            res.push_back(i);
        }
    }

    return res;
}

int main() {
    int m;
    string s;
    cin >> s >> m;

    vector<string> words(m);
    for (int i = 0; i < m; i++) {
        cin >> words[i];
    }

    vector<int> res = findSubstring(s, words);

    if (res.empty()) {
        cout << -1 << endl;
    } else {
        for (const auto& i : res) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}