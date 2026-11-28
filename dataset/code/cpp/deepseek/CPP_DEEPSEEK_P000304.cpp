#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string simplifyPath(string path) {
    stringstream ss(path);
    string segment;
    vector<string> stack;

    while (getline(ss, segment, '/')) {
        if (segment == "" || segment == ".") {
            continue;
        } else if (segment == ".." && !stack.empty()) {
            stack.pop_back();
        } else if (segment == ".." && stack.empty()) {
            continue;
        } else {
            stack.push_back(segment);
        }
    }

    string result;
    for (const auto &s : stack) {
        result += "/" + s;
    }

    return result.empty() ? "/" : result;
}

int main() {
    string path;
    getline(cin, path);

    string simplifiedPath = simplifyPath(path);

    cout << simplifiedPath << endl;

    return 0;
}