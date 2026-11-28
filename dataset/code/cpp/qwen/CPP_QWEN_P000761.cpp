#include <iostream>
#include <string>
using namespace std;

int numDistinctSubsequences(string s, string t, int i, int j) {
    if (j == t.length()) return 1;
    if (i == s.length()) return 0;
    
    if (s[i] == t[j]) {
        return numDistinctSubsequences(s, t, i + 1, j + 1) + numDistinctSubsequences(s, t, i + 1, j);
    } else {
        return numDistinctSubsequences(s, t, i + 1, j);
    }
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << numDistinctSubsequences(s, t, 0, 0) << endl;
    return 0;
}
