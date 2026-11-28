#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int n = a.size();
    for (int i = 0; i <= n; i++) {
        string s1 = a.substr(0, i) + b.substr(n - i);
        string s2 = b.substr(0, i) + a.substr(n - i);
        string r1 = s1, r2 = s2;
        reverse(r1.begin(), r1.end());
        reverse(r2.begin(), r2.end());
        if (s1 == r1 || s2 == r2) { cout << "Yes" << endl; return 0; }
    }
    cout << "No" << endl;
    return 0;
}
