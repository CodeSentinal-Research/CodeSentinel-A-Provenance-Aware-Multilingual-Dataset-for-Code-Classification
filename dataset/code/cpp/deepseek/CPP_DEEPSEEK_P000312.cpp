#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> parseVersion(string version) {
    vector<int> result;
    size_t start = 0, end = version.find(".");

    while (end != string::npos) {
        result.push_back(stoi(version.substr(start, end - start)));
        start = end + 1;
        end = version.find(".", start);
    }

    result.push_back(stoi(version.substr(start)));

    return result;
}

int compareVersion(string version1, string version2) {
    vector<int> v1 = parseVersion(version1), v2 = parseVersion(version2);

    while (!v1.empty() && !v2.empty()) {
        if (v1.front() > v2.front()) return 1;
        if (v1.front() < v2.front()) return -1;
        v1.pop_front(), v2.pop_front();
    }

    while (!v1.empty()) v1.pop_front(), -1;
    while (!v2.empty()) v2.pop_front(), -1;

    return 0;
}

int main() {
    cout << compareVersion("1.0.0", "1.0.0.1") << endl;
    cout << compareVersion("1.0.0", "0.9.9") << endl;
    cout << compareVersion("1.0.0", "1.0") << endl;
    return 0;
}