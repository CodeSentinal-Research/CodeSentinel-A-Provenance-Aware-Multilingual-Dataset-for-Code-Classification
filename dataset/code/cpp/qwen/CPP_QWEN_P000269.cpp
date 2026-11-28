#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; getline(cin, s);
    istringstream iss(s);
    vector<string> w; string t;
    while(iss >> t) w.push_back(t);
    reverse(w.begin(), w.end());
    for(int i=0;i<w.size();i++) cout << w[i] << (i+1==w.size()?"":" ");
    cout << endl;
    return 0;
}
