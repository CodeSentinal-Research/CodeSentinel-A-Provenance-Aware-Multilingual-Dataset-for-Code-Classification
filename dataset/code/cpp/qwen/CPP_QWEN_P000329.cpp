#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    char res = 0;
    for (char c : s) res ^= c;
    for (char c : t) res ^= c;
    cout << res << endl;
    return 0;
}
