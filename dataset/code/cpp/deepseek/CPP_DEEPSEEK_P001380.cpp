#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    sort(s.begin(), s.end(), [&](char a, char b) {
        if (freq[a] != freq[b]) {
            return freq[a] > freq[b];
        }
        return a < b;
    });

    cout << s;
    return 0;
}