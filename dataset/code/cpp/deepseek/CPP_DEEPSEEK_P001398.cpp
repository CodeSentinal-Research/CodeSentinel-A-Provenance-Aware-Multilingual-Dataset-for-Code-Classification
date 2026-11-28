Here's the required C++ code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    
    string common = "";
    for (char c = 'a'; c <= 'z'; c++) {
        int all = true;
        for (int i = 0; i < n; i++) {
            string::iterator it = strs[i].begin();
            while (*it != '\0' && *it == c) {
                it++;
            }
            if (*it != c && *it != '\0') {
                all = false;
                break;
            }
        }
        if (all) {
            common += c;
        }
    }
    
    sort(common.begin(), common.end());
    cout << common;
    return 0;
}
This program works by iterating over each character in the alphabet (a to z). For each character, it checks if all the strings contain the character. If they do, it adds the character to the common string. The common string is then sorted and printed.