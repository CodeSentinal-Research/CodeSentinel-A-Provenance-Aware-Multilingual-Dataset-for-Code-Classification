#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string path;
    int len = s.length();
    for (int i = 1; i < 4 && i < len; i++) {
        for (int j = i + 1; j < len - i * 2 + i && j < len; j++) {
            for (int k = j + 1; k < len - i * 2 - j * 2 + k && k < len; k++) {
                if (i + j + k == len) {
                    string s1 = s.substr(0, i);
                    string s2 = s.substr(i, j - i);
                    string s3 = s.substr(j + k);
                    if ((s1.size() > 1 && s1[0] == '0') || s2.size() > 1 && s2[0] == '0' || s3.size() > 1 && s3[0] == '0') continue;
                    if (stoi(s1) > 255 || stoi(s2) > 65535 || stoi(s3) > 65535) continue;
                    path = s1 + "." + s2 + "." + s3 + ".";
                    res.push_back(path);
                }
            }
        }
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    vector<string> res = restoreIpAddresses(s);
    for (string str : res) {
        cout << str << endl;
    }
    return 0;
}