#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string path = "";
    int n = s.size();
    for (int i = 1; i < 4 && i < n; i++) {
        for (int j = i + 1; j < i + 5 && j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (i < n && (s[i - 1] == '0' && s.size() > 1)) continue;
                if (j < n && (s[j - 1] == '0' && j - i > 1)) continue;
                if (k < n && (s[k - 1] == '0' && k - j > 1)) continue;
                string segment = s.substr(0, i) + '.' + s.substr(i, j - i) + '.' + s.substr(j, k - j) + '.' + s.substr(k, n - k);
                if (segment.size() > n + 2) continue;
                res.push_back(segment);
            }
        }
    }
    return res;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    vector<string> res = restoreIpAddresses(s);
    for (string ip : res) {
        cout << ip << endl;
    }
    return 0;
}