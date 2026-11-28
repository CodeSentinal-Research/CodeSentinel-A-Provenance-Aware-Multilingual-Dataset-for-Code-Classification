#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long dec = 0;
    for (char c : s) {
        dec = dec * 2 + (c - '0');
    }
    cout << dec << endl;
    return 0;
}
