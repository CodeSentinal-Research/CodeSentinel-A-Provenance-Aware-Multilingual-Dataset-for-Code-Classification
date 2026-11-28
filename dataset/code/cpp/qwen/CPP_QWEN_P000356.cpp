#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    char c;
    cin >> s >> c;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) { cout << i << endl; return 0; }
    }
    cout << -1 << endl;
    return 0;
}
