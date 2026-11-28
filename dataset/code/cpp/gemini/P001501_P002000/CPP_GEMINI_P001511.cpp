#include <string>
#include <algorithm>

class Solution {
    int getMax(const std::string& answerKey, int k, char target) {
        int l = 0, cnt = 0;
        for (size_t r = 0; r < answerKey.length(); r++) {
            if (answerKey[r] != target) cnt++;
            if (cnt > k) {
                if (answerKey[l] != target) cnt--;
                l++;
            }
        }
        return answerKey.length() - l;
    }
public:
    int maxConsecutiveAnswers(std::string answerKey, int k) {
        return std::max(getMax(answerKey, k, 'T'), getMax(answerKey, k, 'F'));
    }
};