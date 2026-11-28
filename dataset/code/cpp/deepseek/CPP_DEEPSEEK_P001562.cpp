Here is the C++ solution for the problem:

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int longestSubstring(string S, int K) {
    unordered_map<char, int> m;
    vector<int> count(26, 0);
    int left = 0, right = 0, res = 0;

    while (right < S.size()) {
        count[S[right]]++;
        right++;

        while (m.size() > K) {
            m[S[left]]--;
            if (m[S[left]] == 0) {
                m.erase(S[left]);
            }
            left++;
        }

        if (m.size() == K) {
            res = max(res, right - left);
        }
    }

    return res;
}

int main() {
    string S;
    int K;

    cin >> S >> K;
    cout << longestSubstring(S, K);

    return 0;
}
This code uses a sliding window approach to solve the problem. It keeps track of the number of distinct characters in the current window. When the window size becomes larger than or equal to K, it updates the result if the current window size is larger. The left pointer moves to the right while the number of distinct characters in the current window is less than or equal to K.