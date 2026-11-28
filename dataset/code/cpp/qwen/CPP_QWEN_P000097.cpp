#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool hasZero = s.find('0') != string::npos;
    bool startsZero = s[0] == '0';
    cout << (hasZero && !startsZero ? "Duck" : "Not Duck") << endl;
    return 0;
}
