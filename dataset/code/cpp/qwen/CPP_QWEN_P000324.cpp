#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    string doubled = s + s;
    bool ok = doubled.substr(1, s.size() * 2 - 2).find(s) != string::npos;
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
