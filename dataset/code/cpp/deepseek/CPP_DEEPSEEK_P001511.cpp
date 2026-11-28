#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;

    int maxConsecutive = 0;
    int maxLength = 0;
    int count = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'T') {
            count++;
        } else {
            maxConsecutive = max(maxConsecutive, count);
            count = 0;
        }
    }
    maxConsecutive = max(maxConsecutive, count);

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'T') {
            count++;
        } else {
            if (maxLength < count && k > 0) {
                maxLength = count;
                k--;
            } else {
                maxLength = max(maxLength, count);
                count = 0;
            }
        }
    }
    maxLength = max(maxLength, count);

    cout << maxConsecutive << "\n";
    return 0;
}