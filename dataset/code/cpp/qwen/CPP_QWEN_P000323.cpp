#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int absent = 0, late = 0;
    for (char c : s) {
        if (c == 'A') absent++;
        else if (c == 'L') late++;
        else late = 0;
        if (absent >= 2 || late >= 3) { cout << "No" << endl; return 0; }
    }
    cout << "Yes" << endl;
    return 0;
}
