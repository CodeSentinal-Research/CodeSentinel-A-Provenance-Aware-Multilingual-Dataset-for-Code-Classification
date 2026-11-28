#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int res = 0;
    for (char c : s) {
        res = res * 26 + (c - 'A' + 1);
    }
    cout << res << endl;
    return 0;
}
