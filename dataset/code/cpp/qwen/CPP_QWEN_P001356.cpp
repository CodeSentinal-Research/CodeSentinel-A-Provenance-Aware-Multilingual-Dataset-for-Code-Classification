#include <iostream>
#include <string>
#include <set>
using namespace std;

int maxUniqueSubstrings(string s, int start, set<string>& used) {
    if (start == s.length()) return 0;
    
    int maxCount = 0;
    for (int end = start + 1; end <= s.length(); ++end) {
        string sub = s.substr(start, end - start);
        if (used.find(sub) == used.end()) {
            used.insert(sub);
            maxCount = max(maxCount, 1 + maxUniqueSubstrings(s, end, used));
            used.erase(sub);
        }
    }
    return maxCount;
}

int main() {
    string s;
    cin >> s;
    set<string> used;
    cout << maxUniqueSubstrings(s, 0, used) << endl;
    return 0;
}
