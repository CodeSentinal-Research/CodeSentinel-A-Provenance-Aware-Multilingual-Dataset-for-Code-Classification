#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;

        std::queue<std::pair<std::string, int>> q;
        q.push({beginWord, 1});
        std::unordered_set<std::string> visited = {beginWord};

        while (!q.empty()) {
            auto [word, len] = q.front();
            q.pop();
            if (word == endWord) return len;
            for (size_t i = 0; i < word.length(); i++) {
                char orig = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (words.count(word) && !visited.count(word)) {
                        visited.insert(word);
                        q.push({word, len + 1});
                    }
                }
                word[i] = orig;
            }
        }
        return 0;
    }
};