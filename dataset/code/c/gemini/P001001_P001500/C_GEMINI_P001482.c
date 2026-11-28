#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cmpTokens(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int bagOfTokensScore(int* tokens, int tokensSize, int power) {
    qsort(tokens, tokensSize, sizeof(int), cmpTokens);
    int l = 0, r = tokensSize - 1;
    int score = 0, maxScore = 0;

    // Binary search loop to narrow down range
    while (l <= r) {
        if (power >= tokens[l]) {
            power -= tokens[l++];
            score++;
            maxScore = MAX(maxScore, score);
        } else if (score > 0) {
            power += tokens[r--];
            score--;
        } else {
            break;
        }
    }
    return maxScore;
}