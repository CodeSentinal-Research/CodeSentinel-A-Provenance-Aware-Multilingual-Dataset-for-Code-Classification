#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, int> charToIndex;
vector<int> assignment(10, -1);
vector<bool> usedDigit(10, false);
string w1, w2, w3;

bool isValidAssignment() {
    // Check leading zeros
    if (assignment[w1[0]-'A'] == 0 && w1.length() > 1) return false;
    if (assignment[w2[0]-'A'] == 0 && w2.length() > 1) return false;
    if (assignment[w3[0]-'A'] == 0 && w3.length() > 1) return false;
    
    long long n1 = 0, n2 = 0, n3 = 0;
    for (char c : w1) n1 = n1 * 10 + assignment[c-'A'];
    for (char c : w2) n2 = n2 * 10 + assignment[c-'A'];
    for (char c : w3) n3 = n3 * 10 + assignment[c-'A'];
    
    return n1 + n2 == n3;
}

bool solve(int idx, vector<char>& uniqueChars) {
    if (idx == uniqueChars.size()) {
        return isValidAssignment();
    }
    
    char c = uniqueChars[idx];
    for (int d = 0; d <= 9; ++d) {
        if (!usedDigit[d]) {
            assignment[c-'A'] = d;
            usedDigit[d] = true;
            if (solve(idx + 1, uniqueChars)) return true;
            usedDigit[d] = false;
            assignment[c-'A'] = -1;
        }
    }
    return false;
}

int main() {
    cin >> w1 >> w2 >> w3;
    
    vector<char> uniqueChars;
    map<char, bool> seen;
    for (char c : w1) if (!seen[c]) { uniqueChars.push_back(c); seen[c] = true; }
    for (char c : w2) if (!seen[c]) { uniqueChars.push_back(c); seen[c] = true; }
    for (char c : w3) if (!seen[c]) { uniqueChars.push_back(c); seen[c] = true; }
    
    if (uniqueChars.size() > 10) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    if (solve(0, uniqueChars)) {
        for (char c : uniqueChars) {
            cout << c << "=" << assignment[c-'A'] << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
