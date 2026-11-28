#include <iostream>
#include <vector>
#include <string>

using namespace std;

void restoreIpAddresses(string s, int start, vector<string> &result, string current) {
    if (result.size() == 4 && start == s.size()) {
        result.push_back(current);
        return;
    }

    if (result.size() == 4 && start < s.size()) {
        return;
    }

    if (result.size() + (s.size() - start + 1) / 3 < 4) {
        return;
    }

    for (int i = 1; i <= 3 && start + i - 1 < s.size(); ++i) {
        string part = s.substr(start, i);

        if (part[0] == '0' && part.size() > 1) {
            return;
        }

        int num = stoi(part);

        if (num > 255) {
            return;
        }

        if (result.size() == 4 && i != 1) {
            break;
        }
        restoreIpAddresses(s, start + i, result, current + part + (i == 1 ? "" : "."));
    }
}

int main() {
    string s;
    cin >> s;

    vector<string> result;
    restoreIpAddresses(s, 0, result, "");

    for (string ip : result) {
        cout << ip << endl;
    }

    return 0;
}
This C++ code works by recursively trying all possible ways to split the input string into three segments. If the length of a segment is more than 1 and the first segment is not '0', it's added to the current IP string. Once the segments are all used up, the function returns and checks if the current IP is a valid IP.