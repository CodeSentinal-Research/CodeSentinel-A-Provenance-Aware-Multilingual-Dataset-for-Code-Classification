#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int getMaxAns(char* answerKey, int k, char target) {
    int l = 0, cnt = 0, len = 0;
    for (int r = 0; answerKey[r]; r++) {
        if (answerKey[r] != target) cnt++;
        if (cnt > k) {
            if (answerKey[l] != target) cnt--;
            l++;
        }
        len++;
    }
    return len - l;
}

int maxConsecutiveAnswers(char* answerKey, int k) {
    return MAX(getMaxAns(answerKey, k, 'T'), getMaxAns(answerKey, k, 'F'));
}