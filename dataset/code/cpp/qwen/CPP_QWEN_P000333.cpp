#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<string> words(m);
    for (int i = 0; i < m; i++) cin >> words[i];
    int count = 0;
    for (const string& word : words) {
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            if (s[i] == word[j]) j++;
            i++;
        }
        if (j == word.size()) count++;
    }
    cout << count << endl;
    return 0;
}
