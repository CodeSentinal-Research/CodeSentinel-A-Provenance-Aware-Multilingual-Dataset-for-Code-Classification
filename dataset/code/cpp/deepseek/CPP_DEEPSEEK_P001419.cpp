#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    vector<pair<char, int>> freq(256, {0, 0});
    for (char c : str) {
        freq[c] = make_pair(freq[c].first + 1, freq[c].second);
    }

    sort(freq.begin(), freq.end(), [](pair<char, int> a, pair<char, int> b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    string result;
    for (pair<char, int> p : freq) {
        result += string(p.second, p.first);
    }

    cout << result << endl;

    return 0;
}
This code first calculates the frequency of each character in the input string. It then sorts the frequencies in descending order of their frequency. If two frequencies are equal, it sorts the characters lexicographically. The rearranged string is then printed to the console.