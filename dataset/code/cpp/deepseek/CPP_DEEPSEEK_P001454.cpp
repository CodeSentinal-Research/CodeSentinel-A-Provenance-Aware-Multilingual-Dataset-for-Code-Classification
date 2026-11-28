#include <iostream>
#include <string>
#include <set>

using namespace std;

int countDistinctSubstrings(string s) {
    set<string> substrings;

    for (int len = 1; len <= s.length(); len++) {
        for (int i = 0; i <= s.length() - len; i++) {
            string substring = s.substr(i, len);
            substrings.insert(substring);
        }
    }

    return substrings.size();
}

int main() {
    string s;
    cin >> s;

    cout << countDistinctSubstrings(s) << endl;

    return 0;
}