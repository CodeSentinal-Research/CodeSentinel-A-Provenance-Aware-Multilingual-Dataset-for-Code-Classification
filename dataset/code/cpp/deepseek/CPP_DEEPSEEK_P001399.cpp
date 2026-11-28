#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    unordered_map<string, int> cnt1, cnt2;
    for (auto &c : s1) c = tolower(c);
    for (auto &c : s2) c = tolower(c);
    istringstream ss1(s1), ss2(s2);
    string word;
    while (ss1 >> word) cnt1[word]++;
    while (ss2 >> word) cnt2[word]++;

    for (auto &p : cnt1) {
        if (cnt2.find(p.first) == cnt2.end()) cout << p.first << endl;
    }
    return 0;
}