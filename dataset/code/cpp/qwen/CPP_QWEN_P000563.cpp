#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int main() {
    string beginWord, endWord;
    int n;
    cin >> beginWord >> endWord >> n;
    vector<string> wordList(n);
    for (int i = 0; i < n; i++) cin >> wordList[i];
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (dict.find(endWord) == dict.end()) {
        cout << 0 << endl;
        return 0;
    }
    queue<string> q;
    q.push(beginWord);
    int level = 1;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            string word = q.front(); q.pop();
            if (word == endWord) {
                cout << level << endl;
                return 0;
            }
            for (int j = 0; j < word.size(); j++) {
                char orig = word[j];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[j] = c;
                    if (dict.find(word) != dict.end()) {
                        q.push(word);
                        dict.erase(word);
                    }
                }
                word[j] = orig;
            }
        }
        level++;
    }
    cout << 0 << endl;
    return 0;
}
