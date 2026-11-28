#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkSplit(string s, long long prevNum, bool started) {
    if (s.empty()) return started;
    
    for (int len = 1; len <= s.length(); ++len) {
        string partStr = s.substr(0, len);
        if (partStr.length() > 1 && partStr[0] == '0') break;
        
        long long num = stoll(partStr);
        if (started && num != prevNum - 1) continue;
        
        if (checkSplit(s.substr(len), num, true)) return true;
        
        if (started) break; 
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    cout << (checkSplit(s, 0, false) ? "YES" : "NO") << endl;
    return 0;
}
