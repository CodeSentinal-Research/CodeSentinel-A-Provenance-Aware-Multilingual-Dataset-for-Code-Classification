#include <iostream>
#include <string>
using namespace std;

int main() {
    string word, abbr;
    cin >> word >> abbr;
    int i = 0, j = 0;
    while (i < word.size() && j < abbr.size()) {
        if (isdigit(abbr[j])) {
            if (abbr[j] == '0') { cout << "No" << endl; return 0; }
            int num = 0;
            while (j < abbr.size() && isdigit(abbr[j])) {
                num = num * 10 + (abbr[j] - '0');
                j++;
            }
            i += num;
        } else {
            if (word[i] != abbr[j]) { cout << "No" << endl; return 0; }
            i++; j++;
        }
    }
    cout << (i == word.size() && j == abbr.size() ? "Yes" : "No") << endl;
    return 0;
}
