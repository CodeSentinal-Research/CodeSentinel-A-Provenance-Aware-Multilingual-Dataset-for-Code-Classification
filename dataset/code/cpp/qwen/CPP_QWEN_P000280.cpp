#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b; cin >> a >> b;
    vector<int> ca(26,0), cb(26,0);
    for(char c : a) ca[c-'a']++;
    for(char c : b) cb[c-'a']++;
    int diff = 0;
    for(int i=0;i<26;i++) diff += abs(ca[i]-cb[i]);
    cout << (diff<=1?"Yes":"No") << endl;
    return 0;
}
