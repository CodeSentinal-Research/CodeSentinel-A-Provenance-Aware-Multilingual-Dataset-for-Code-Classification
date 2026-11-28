Here is the C++ code that will solve the problem.

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s1[1001], s2[1001];
    cin >> s1 >> s2;

    int count1[26] = {0}, count2[26] = {0};
    for (int i = 0; s1[i] != '\0'; i++)
        count1[s1[i] - 'a']++;
    for (int i = 0; s2[i] != '\0'; i++)
        count2[s2[i] - 'a']++;

    int diff = 0;
    for (int i = 0; i < 26; i++) {
        diff += abs(count1[i] - count2[i]);
    }

    if (diff > 1) {
        cout << "No" << endl;
    } else {
        int len = strlen(s1);
        for (int i = 0; i < len; i++) {
            int c = s1[i] - 'a';
            if (count1[c] > 0 && count2[c] > 0) {
                count1[c]--;
                count2[c]--;
                break;
            }
        }
        int valid = 1;
        for (int i = 0; i < 26; i++) {
            valid &= (count1[i] == count2[i]);
        }
        if (valid) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
This code firstly checks the number of each character in both strings and then computes the number of characters that are different between two strings. If the number of characters that are different is more than 1, it means that we can't make the strings anagrams after removing at most one character. Otherwise, it tries to remove one character from the first string to make the two strings anagrams. Then it checks if we can make the two strings anagrams by removing at most one character.