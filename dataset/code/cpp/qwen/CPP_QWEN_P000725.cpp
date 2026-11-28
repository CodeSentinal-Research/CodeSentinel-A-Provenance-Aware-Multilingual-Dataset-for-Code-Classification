#include <iostream>
#include <string>
using namespace std;

bool checkSplit(string s, long long prevNum, bool started) {
    if (s.empty()) return started;
    
    for (int len = 1; len <= s.length(); ++len) {
        string partStr = s.substr(0, len);
        if (partStr.length() > 1 && partStr[0] == '0') break;
        
        long long num = stoll(partStr);
        if (started && num != prevNum - 1) continue;
        
        if (checkSplit(s.substr(len), num, true)) return true;
        
        // Optimization: if numbers are getting too big or logic fails, break? 
        // Strictly descending by 1 means next must be prev-1.
        if (started) break; 
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    cout << (checkSplit(s, 0, false) ? "true" : "false") << endl;
    return 0;
}
