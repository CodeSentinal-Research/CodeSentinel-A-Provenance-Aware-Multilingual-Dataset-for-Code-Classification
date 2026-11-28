#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; char c; cin >> s >> c;
    s.erase(remove(s.begin(), s.end(), c), s.end());
    cout << s << endl;
    return 0;
}
