#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;

    unordered_map<char, int> freq;
    unordered_map<char, int> pos;

    int left = 0, right = 0;
    int result = 0;

    while (right < s.length()) {
        freq[s[right]]++;
        pos[s[right]] = right;

        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            left++;
        }

        if (right - left + 1 > result) {
            result = right - left + 1;
        }

        right++;
    }

    cout << result;
    return 0;
}