#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string word, abbr;
    cin >> word >> abbr;
    
    int i = 0, j = 0;
    while (i < word.size() && j < abbr.size()) {
        if (word[i] == abbr[j] && word[i] != '[') {
            i++;
            j++;
        } else if (word[i] == '[') {
            int count = 0;
            while (word[i] != ']') {
                i++;
                count = (count * 10) + (word[i] - '0');
            }
            i++;
            for (int k = 0; k < count; k++) {
                if (j == abbr.size() || word[i+k] != abbr[j+k]) {
                    cout << "No";
                    return 0;
                }
            }
            j += count;
            if (j == abbr.size()) break;
        } else if (word[i] != abbr[j]) {
            cout << "No";
            return 0;
        } else {
            i++;
            j++;
        }
    }
    if (i < word.size() || j < abbr.size()) {
        cout << "No";
        return 0;
    }
    cout << "Yes";
    return 0;
}