#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    unordered_map<string, vector<string>> groups;
    for (const auto& s : strings) {
        sort(s.begin(), s.end());
        groups[s].push_back(s);
    }

    for (const auto& kv : groups) {
        cout << "Group of anagrams: ";
        for (const auto& s : kv.second) {
            cout << s << " ";
        }
        cout << "\n";
    }

    return 0;
}
This C++ code will read the number of strings from the standard input, then read those strings. It will then sort each string alphabetically and use an unordered map to group the strings by the sorted string. Each group is printed on a separate line with the group of anagrams.