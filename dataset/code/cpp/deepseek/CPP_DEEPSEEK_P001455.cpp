Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int len = s.length();
    vector<int> count(256, 0);
    vector<int> len_array(256, 0);
    int start = 0, max_len = 0, max_i = 0;

    for (int i = 0; i < len; i++) {
        count[s[i]]++;
        if (max_len < count[s[i]]) {
            max_len = count[s[i]];
            max_i = i;
        }
    }

    for (int i = 0; i < len; i++) {
        if (max_i - i + 1 > max_len) {
            for (int k = 0; k < len; k++) {
                if (i + k <= max_i && len_array[s[k]] == 0) {
                    len_array[s[k]] = i + k;
                    if (k + max_len < len && len_array[s[k + max_len]] == i + max_len) {
                        start = i;
                    }
                } else {
                    break;
                }
            }
        }
    }

    if (max_len == 0) {
        cout << "";
    } else {
        cout << s.substr(start, max_len);
    }

    return 0;
}
This C++ code uses the concept of Tortoise's Hare algorithm to find the longest duplicate substring in a given string. It first computes the count of each character in the string and then iterates over the string again to find the longest duplicate substring. The reason why it uses the tortoise and hare approach is because the tortoise moves one step at a time, while the hare moves two steps at a time. When they meet, that's the end of the longest duplicate substring.