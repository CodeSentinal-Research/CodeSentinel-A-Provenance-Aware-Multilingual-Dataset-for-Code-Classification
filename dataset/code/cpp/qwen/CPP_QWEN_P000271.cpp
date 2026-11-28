#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b; cin >> a >> b;
    if(a.size()!=b.size()) { cout << "No" << endl; return 0; }
    string c = a+a;
    cout << (c.find(b)!=string::npos?"Yes":"No") << endl;
    return 0;
}
