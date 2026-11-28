#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    int k;

    cin >> s;
    cin >> k;

    int maxLength = 0;
    int count[26] = {0};
    int start = 0;

    for (int i = 0; i < s.size(); i++) {
        if (count[s[i] - 'a'] >= start) {
            start = count[s[i] - 'a'] + 1;
        }

        maxLength = max(maxLength, i - start + 1);
        count[s[i] - 'a'] = i;
    }

    cout << maxLength << "\n";

    return 0;
}
This program uses a sliding window approach to solve the problem. It keeps track of the start index of the longest substring that can be converted into a string of identical characters after replacing at most K characters. It also counts the occurrence of each character in the string.