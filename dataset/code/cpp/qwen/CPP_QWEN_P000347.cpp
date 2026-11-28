#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    for (int i = 0; i < s.size(); i += 2 * k) {
        reverse(s.begin() + i, s.begin() + min(i + k, (int)s.size()));
    }
    cout << s << endl;
    return 0;
}
