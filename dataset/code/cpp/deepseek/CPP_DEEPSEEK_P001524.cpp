#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;

    int start = 0, maxLen = 0;
    for (int end = 0; end < s.size(); ++end) {
        if (s[end] == 'T') {
            if (end - start + 1 > maxLen) {
                maxLen = end - start + 1;
            }
        } else {
            start = end + 1;
        }
    }

    cout << maxLen << endl;

    return 0;
}