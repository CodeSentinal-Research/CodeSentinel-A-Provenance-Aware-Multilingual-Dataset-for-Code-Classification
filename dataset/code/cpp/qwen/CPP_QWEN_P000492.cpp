#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;
string simplifyPath(string path) {
    stringstream ss(path);
    string token;
    stack<string> st;
    while(getline(ss, token, '/')) {
        if(token == "" || token == ".") continue;
        if(token == "..") { if(!st.empty()) st.pop(); }
        else st.push(token);
    }
    string res = "";
    while(!st.empty()) { res = "/" + st.top() + res; st.pop(); }
    return res.empty() ? "/" : res;
}
int main() {
    string path; cin >> path;
    cout << simplifyPath(path) << endl;
    return 0;
}
