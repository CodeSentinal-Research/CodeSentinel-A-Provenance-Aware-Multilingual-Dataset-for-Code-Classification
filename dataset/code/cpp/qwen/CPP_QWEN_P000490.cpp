#include <iostream>
#include <string>
using namespace std;
string process(string s) {
    string res = "";
    for(char c : s) {
        if(c == '#') { if(!res.empty()) res.pop_back(); }
        else res += c;
    }
    return res;
}
int main() {
    string s, t; cin >> s >> t;
    cout << (process(s) == process(t) ? "true" : "false") << endl;
    return 0;
}
