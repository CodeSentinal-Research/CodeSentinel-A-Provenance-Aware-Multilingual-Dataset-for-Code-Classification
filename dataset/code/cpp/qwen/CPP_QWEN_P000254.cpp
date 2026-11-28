#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    int c = count_if(s.begin(), s.end(), [](char c){ return isalpha(c) && string("aeiouAEIOU").find(c)==string::npos; });
    cout << c << endl;
    return 0;
}
