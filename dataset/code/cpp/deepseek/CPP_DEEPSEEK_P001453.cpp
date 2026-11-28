#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    map<char, int> counts;
    for (char c : s) {
        counts[c]++;
    }

    char maxChar = 'a';
    int maxFreq = 0;
    for (auto& kv : counts) {
        if (kv.second > maxFreq) {
            maxChar = kv.first;
            maxFreq = kv.second;
        } else if (kv.second == maxFreq && kv.first < maxChar) {
            maxChar = kv.first;
        }
    }

    cout << maxChar << ' ' << maxFreq;

    return 0;
}