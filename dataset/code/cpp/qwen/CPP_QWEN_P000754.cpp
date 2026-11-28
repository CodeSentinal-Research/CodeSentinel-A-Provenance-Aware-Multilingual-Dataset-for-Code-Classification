#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void generateCasePermutations(string s, int index, string current, vector<string>& result) {
    if (index == s.length()) {
        result.push_back(current);
        return;
    }
    
    if (isalpha(s[index])) {
        generateCasePermutations(s, index + 1, current + (char)tolower(s[index]), result);
        generateCasePermutations(s, index + 1, current + (char)toupper(s[index]), result);
    } else {
        generateCasePermutations(s, index + 1, current + s[index], result);
    }
}

int main() {
    string s;
    cin >> s;
    vector<string> result;
    generateCasePermutations(s, 0, "", result);
    sort(result.begin(), result.end());
    
    for (const string& perm : result) {
        cout << perm << endl;
    }
    return 0;
}
