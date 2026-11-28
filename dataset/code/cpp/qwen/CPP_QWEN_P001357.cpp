#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isAdditive(string s, int start, long long first, long long second, bool hasStarted) {
    if (start == s.length()) return hasStarted;
    
    long long num = 0;
    for (int i = start; i < s.length(); ++i) {
        if (i > start && s[start] == '0') break;
        num = num * 10 + (s[i] - '0');
        
        if (!hasStarted) {
            if (!hasStarted && first == -1) {
                if (isAdditive(s, i + 1, num, second, false)) return true;
            } else if (second == -1) {
                if (isAdditive(s, i + 1, first, num, true)) return true;
            }
        } else {
            if (num == first + second) {
                if (isAdditive(s, i + 1, second, num, true)) return true;
            }
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    cout << (isAdditive(s, 0, -1, -1, false) ? "YES" : "NO") << endl;
    return 0;
}
