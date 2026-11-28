#include <iostream>
#include <string>
#include <vector>
using namespace std;

void restoreIpAddresses(string s, int start, int dots, string current, vector<string>& result) {
    if (dots == 3) {
        string lastPart = s.substr(start);
        if (lastPart.empty()) return;
        if (lastPart.length() > 1 && lastPart[0] == '0') return;
        int val = stoi(lastPart);
        if (val >= 0 && val <= 255) {
            result.push_back(current + lastPart);
        }
        return;
    }
    
    for (int len = 1; len <= 3; ++len) {
        if (start + len > s.length()) break;
        string part = s.substr(start, len);
        if (part.length() > 1 && part[0] == '0') break;
        int val = stoi(part);
        if (val >= 0 && val <= 255) {
            restoreIpAddresses(s, start + len, dots + 1, current + part + ".", result);
        }
    }
}

int main() {
    string s;
    cin >> s;
    vector<string> result;
    restoreIpAddresses(s, 0, 0, "", result);
    
    for (const string& ip : result) {
        cout << ip << endl;
    }
    return 0;
}
