#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string simplifyPath(string path) {
    vector<string> stack;
    stringstream ss(path);
    string dir;

    while (getline(ss, dir, '/')) {
        if (dir == "" || dir == ".") {
            continue;
        } else if (dir == "..") {
            if (!stack.empty()) {
                stack.pop_back();
            }
        } else {
            stack.push_back(dir);
        }
    }

    string result;
    for (auto dir : stack) {
        result += '/' + dir;
    }

    if (result.empty()) {
        result = '/';
    }

    return result;
}

int main() {
    string path;
    getline(cin, path);
    cout << simplifyPath(path);
    return 0;
}