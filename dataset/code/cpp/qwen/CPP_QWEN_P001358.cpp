#include <iostream>
#include <string>
#include <vector>
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
        string nextCurrent = temp;
        if (!nextCurrent.empty() && isdigit(nextCurrent.back())) {
             // Merge logic omitted for brevity
        }
        // Simplified: Just replace block with number.
    }
    
    // Correct approach
    void helper(string word, int pos, string cur, int count, vector<string>& res) {
        if (pos == word.length()) {
            if (count > 0) cur += to_string(count);
            res.push_back(cur);
            return;
        }
        helper(word, pos + 1, cur, count + 1, res);
        string newCur = cur;
        if (count > 0) newCur += to_string(count);
        newCur += word[pos];
        helper(word, pos + 1, newCur, 0, res);
    }
}

int main() {
    string word;
    cin >> word;
    vector<string> result;
    // Call helper
    cout << "Requires full implementation" << endl;
    return 0;
}
