#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> w1(n), w2(n);
    for (int i = 0; i < n; i++) cin >> w1[i];
    for (int i = 0; i < n; i++) cin >> w2[i];
    string s1 = "", s2 = "";
    for (const string& w : w1) s1 += w;
    for (const string& w : w2) s2 += w;
    cout << (s1 == s2 ? "Yes" : "No") << endl;
    return 0;
}
