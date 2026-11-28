Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int maxLength(vector<string> &words) {
    int maxLength = 0;
    vector<int> dp(1 << words.size(), 0);
    vector<int> dp2(1 << words.size(), 1 << words.size() - 1);
    for (int mask = 0; mask < 1 << words.size(); ++mask) {
        if (__builtin_popcount(mask) > 1) {
            continue;
        }
        bool flag = false;
        for (int i = 0; i < words.size(); ++i) {
            if ((mask >> i) & 1) {
                for (char c : words[i]) {
                    if ((mask >> (c - 'a')) & 1) {
                        flag = true;
                        break;
                    }
                    (mask >>= (c - 'a')) &= ~1;
                }
                if (!flag) {
                    break;
                }
            }
        }
        if (flag) {
            for (int i = 0; i < words.size(); ++i) {
                if ((mask >> i) & 1) {
                    for (char c : words[i]) {
                        (mask >>= (c - 'a')) &= ~1;
                    }
                }
            }
            for (int i = 0; i < words.size(); ++i) {
                if ((mask >> i) & 1) {
                    for (char c : words[i]) {
                        (mask >>= (c - 'a')) &= ~1;
                    }
                }
            }
            dp[mask] = max(dp[mask], dp2[mask] + 2);
            maxLength = max(maxLength, dp[mask]);
        }
    }
    return maxLength;
}

int main() {
    vector<string> words = {"a", "b", "ab", "abc", "bc", "cd"};
    cout << maxLength(words) << endl;
    return 0;
}

The code above uses dynamic programming to solve the problem. The main idea is to use bitmask to represent the state of the string, where each bit in the mask represents a character in the string. If the bit is set, then the character can be included in the string, otherwise it cannot.

The dp array stores the maximum length of the string that can be formed with unique characters, while dp2 array stores the maximum length of the string that can be formed with unique characters without repeating characters.

The main loop in the code iterates through all possible bitmasks, and for each bitmask, if it's not a power of two, we can find all words that can be formed with the current character set. If there's no such word, then we can ignore it, otherwise we include it in the maximum length.

The time complexity of this code is O(n * 2^n), where n is the number of words.