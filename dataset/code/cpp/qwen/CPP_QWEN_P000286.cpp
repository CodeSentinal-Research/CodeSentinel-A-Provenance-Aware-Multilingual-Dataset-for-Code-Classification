#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    int l=0, r=s.size()-1;
    while(l<r) {
        while(l<r && !isalpha(s[l])) l++;
        while(l<r && !isalpha(s[r])) r--;
        if(l<r) swap(s[l++], s[r--]);
    }
    cout << s << endl;
    return 0;
}
