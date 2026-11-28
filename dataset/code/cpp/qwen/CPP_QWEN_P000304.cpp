#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    string path;
    cin >> path;
    vector<string> stack;
    stringstream ss(path);
    string token;
    while (getline(ss, token, '/')) {
        if (token == "..") {
            if (!stack.empty()) stack.pop_back();
        } else if (token != "." && !token.empty()) {
            stack.push_back(token);
        }
    }
    string res = "/";
    for (int i = 0; i < stack.size(); i++) {
        if (i > 0) res += "/";
        res += stack[i];
    }
    cout << res << endl;
    return 0;
}
