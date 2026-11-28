Here is the C++ code for the problem:

#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

bool isTransformable(string word, string target, unordered_set<string>& dict) {
    int diff = 0;
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] != target[i]) {
            ++diff;
            if (diff > 1) {
                return false;
            }
        }
    }
    return diff == 1;
}

int ladderLength(string start, string end, unordered_set<string>& dict) {
    queue<pair<string, int>> q;
    q.push({start, 1});
    dict.insert(end);

    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        string word = node.first;
        int level = node.second;

        if (word == end) {
            return level;
        }

        for (int i = 0; i < word.size(); ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (word[i] == c) {
                    continue;
                }
                string newWord = word;
                newWord[i] = c;
                if (dict.count(newWord)) {
                    q.push({newWord, level + 1});
                    dict.erase(newWord);
                }
            }
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    unordered_set<string> dict;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        dict.insert(word);
    }
    string start, end;
    cin >> start >> end;
    int level = ladderLength(start, end, dict);
    cout << level << endl;
    return 0;
}

This code first reads in the dictionary words and the start and end words. Then it calls the `ladderLength` function, which uses a breadth-first search (BFS) to find the minimum length of the ladder from the start word to the end word. The `isTransformable` function is used to check if two words are transformationally equivalent.