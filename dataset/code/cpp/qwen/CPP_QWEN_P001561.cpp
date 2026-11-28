#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    int m;
    cin >> s >> m;
    vector<string> words(m);
    for (int i = 0; i < m; ++i) cin >> words[i];
    
    if (words.empty() || s.empty()) {
        cout << -1 << endl;
        return 0;
    }
    
    int wordLen = words[0].length();
    int numWords = words.size();
    int totalLen = wordLen * numWords;
    
    if (s.length() < totalLen) {
        cout << -1 << endl;
        return 0;
    }
    
    unordered_map<string, int> wordCount;
    for (string& w : words) wordCount[w]++;
    
    vector<int> result;
    
    for (int i = 0; i < wordLen; ++i) {
        int left = i, right = i;
        int count = 0;
        unordered_map<string, int> seen;
        
        while (right + wordLen <= s.length()) {
            string word = s.substr(right, wordLen);
            right += wordLen;
            
            if (wordCount.find(word) != wordCount.end()) {
                seen[word]++;
                count++;
                
                while (seen[word] > wordCount[word]) {
                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    count--;
                    left += wordLen;
                }
                
                if (count == numWords) {
                    result.push_back(left);
                }
            } else {
                seen.clear();
                count = 0;
                left = right;
            }
        }
    }
    
    if (result.empty()) cout << -1 << endl;
    else {
        for (int idx : result) cout << idx << " ";
        cout << endl;
    }
    
    return 0;
}
