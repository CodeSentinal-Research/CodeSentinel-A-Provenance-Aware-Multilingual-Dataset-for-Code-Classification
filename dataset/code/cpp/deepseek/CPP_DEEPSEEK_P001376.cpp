Here is the C++ code to solve the given problem:

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        getline(cin, strs[i]);
    }

    for (int i = 0; i < n; i++) {
        sort(strs[i].begin(), strs[i].end());
    }

    vector<vector<string>> groups;
    vector<string> currentGroup;
    currentGroup.push_back(strs[0]);

    for (int i = 1; i < n; i++) {
        if (strs[i] == currentGroup[0]) continue; 
        if (strs[i] == currentGroup[0] && i < n && strs[i + 1] == currentGroup[0]) {
            currentGroup.push_back(strs[i + 1]);
            i++;
        } else {
            groups.push_back(currentGroup);
            currentGroup.clear();
            currentGroup.push_back(strs[i]);
        }
    }
    groups.push_back(currentGroup); 

    for (const auto &group : groups) {
        for (const auto &str : group) {
            cout << str << "\n";
        }
    }

    return 0;
}
This code reads the input strings, sorts them, and groups them together based on the sorted string. It then prints each group of anagrams on a separate line.