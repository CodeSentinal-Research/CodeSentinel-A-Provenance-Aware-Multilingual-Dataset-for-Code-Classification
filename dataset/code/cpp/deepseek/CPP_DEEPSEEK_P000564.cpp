Here is a C++ solution for the problem:

#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
    unordered_set<string> visited, next_visit;
    queue<vector<string>> bfs;
    bfs.push({beginWord});
    visited.insert(beginWord);

    vector<vector<string>> res;
    while (!bfs.empty()) {
        vector<string> path = bfs.front(); bfs.pop();
        if (path.size() - 1 > res.size()) continue;
        if (path.size() - 1 == res.size()) res.push_back(path);
        if (path.back() == endWord) return res;

        for (int i = 0; i < path.size(); ++i) {
            string word = path[i];
            for (int j = 0; j < word.size(); ++j) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (word[j] == c) continue;
                    string new_word = word;
                    new_word[j] = c;
                    if (new_word == endWord) return vector<vector<string>>(1, path);
                    if (visited.count(new_word)) continue;
                    next_visit.insert(new_word);
                    bfs.push({path});
                }
            }
        }

        swap(visited, next_visit);
        next_visit.clear();
    }

    return res;
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    unordered_set<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> res = findLadders(beginWord, endWord, wordList);
    for (const auto &path : res) {
        for (const auto &word : path) {
            cout << word << ' ';
        }
        cout << endl;
    }

    return 0;
}

This code uses a Breadth-First Search (BFS) algorithm to find all shortest transformation sequences from the beginWord to the endWord. The BFS algorithm uses a queue to keep track of the current level of the search, and an unordered set to keep track of visited nodes.

In each iteration of the BFS, it pops the current level of the search from the queue, and then adds all words that can be formed from this word in the given word list to the next level of the search. If a word in the next level of the search is the endWord, it returns the path from beginWord to endWord. If a word in the next level of the search is already visited, it skips it.

In each iteration of the BFS, it swaps the visited set with the next_visit set, which contains all words that have not been visited yet. It then clears the next_visit set to prepare for the next level of the search.

The BFS algorithm runs in O(n) time, where n is the total number of words in the dictionary.