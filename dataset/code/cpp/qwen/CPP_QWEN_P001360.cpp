#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int maxScore(vector<string>& words, vector<int>& letterCount, vector<int>& scores, int index) {
    if (index == words.size()) return 0;
    
    // Skip current word
    int skip = maxScore(words, letterCount, scores, index + 1);
    
    // Try to take current word
    vector<int> tempCount = letterCount;
    int wordScore = 0;
    bool canTake = true;
    for (char c : words[index]) {
        if (tempCount[c-'a'] <= 0) {
            canTake = false;
            break;
        }
        tempCount[c-'a']--;
        wordScore += scores[c-'a'];
    }
    
    int take = 0;
    if (canTake) {
        take = wordScore + maxScore(words, tempCount, scores, index + 1);
    }
    
    return max(skip, take);
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) cin >> words[i];
    
    string letters;
    cin >> letters;
    vector<int> letterCount(26, 0);
    for (char c : letters) letterCount[c-'a']++;
    
    vector<int> scores(26);
    for (int i = 0; i < 26; ++i) cin >> scores[i];
    
    cout << maxScore(words, letterCount, scores, 0) << endl;
    return 0;
}
