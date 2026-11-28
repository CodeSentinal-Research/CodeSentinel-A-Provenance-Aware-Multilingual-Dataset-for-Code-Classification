#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void generateAbbreviations(string word, int index, string current, vector<string>& result) {
    if (index == word.length()) {
        result.push_back(current);
        return;
    }
    
    // Abbreviate
    int count = 0;
    string temp = current;
    while (index < word.length()) {
        count++;
        index++;
        // Replace consecutive chars with count
        string nextCurrent = temp;
        if (!nextCurrent.empty() && isdigit(nextCurrent.back())) {
             // Merge digits? No, standard abbr keeps them separate or merges. 
             // Generalized abbreviation usually merges: "w1rd" vs "w1r1d". 
             // Leetcode 320 merges.
             // Let's assume simple replacement first then merge logic is complex.
             // Actually, standard "Generalized Abbreviation" allows merging.
             // To keep it simple for recursion:
             // Option 1: Keep char
             // Option 2: Start/Continue number
        }
        // Simplified: Just replace block with number.
        // This is hard to do cleanly in simple recursion without backtracking numbers.
        // Let's use the standard backtracking for abbreviations.
    }
}

// Correct approach for Generalized Abbreviation
void helper(string word, int pos, string cur, int count, vector<string>& res) {
    if (pos == word.length()) {
        if (count > 0) cur += to_string(count);
        res.push_back(cur);
        return;
    }
    
    // Abbreviate current character
    helper(word, pos + 1, cur, count + 1, res);
    
    // Keep current character
    string newCur = cur;
    if (count > 0) newCur += to_string(count);
    newCur += word[pos];
    helper(word, pos + 1, newCur, 0, res);
}

int main() {
    string word;
    cin >> word;
    vector<string> result;
    helper(word, 0, "", 0, result);
    sort(result.begin(), result.end());
    
    for (const string& abbr : result) {
        cout << abbr << endl;
    }
    return 0;
}
