#include <iostream>
#include <sstream>
using namespace std;

string decodeString(string s) {
    int n = s.length();
    string res = "";
    int i = 0;
    while (i < n) {
        if (s[i] == '[') {
            i++;
            string temp = "";
            while (s[i] != ']') {
                temp += s[i];
                i++;
            }
            i++;
            int repeat = stoi(temp);
            string substring = decodeString(s.substr(i));
            while (repeat--)
                res += substring;
        } else {
            res += s[i];
            i++;
        }
    }
    return res;
}

int main() {
    string s;
    getline(cin, s);
    cout << decodeString(s);
    return 0;
}