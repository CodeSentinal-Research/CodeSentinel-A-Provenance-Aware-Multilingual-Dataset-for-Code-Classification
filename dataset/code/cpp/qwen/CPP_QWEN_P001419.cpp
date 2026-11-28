#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    
    vector<pair<int, char>> chars;
    for (auto& [c, count] : freq) chars.push_back({count, c});
    
    sort(chars.begin(), chars.end(), [](const pair<int,char>& a, const pair<int,char>& b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });
    
    string result = "";
    for (auto& [count, c] : chars) {
        result += string(count, c);
    }
    
    cout << result << endl;
    return 0;
}
