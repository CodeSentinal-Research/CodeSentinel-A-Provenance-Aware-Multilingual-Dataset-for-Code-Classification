#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int backtrackWords(int idx, char** words, int wordsSize, int count[26], int* score) {
    if (idx == wordsSize) return 0;
    int maxS = backtrackWords(idx + 1, words, wordsSize, count, score);

    char* w = words[idx];
    int wCount[26] = {0};
    int wScore = 0, canForm = 1;

    for (int i = 0; w[i]; i++) {
        int code = w[i] - 'a';
        wCount[code]++;
        wScore += score[code];
        if (wCount[code] > count[code]) canForm = 0;
    }

    if (canForm) {
        for (int i = 0; i < 26; i++) count[i] -= wCount[i];
        maxS = MAX(maxS, wScore + backtrackWords(idx + 1, words, wordsSize, count, score));
        for (int i = 0; i < 26; i++) count[i] += wCount[i];
    }
    return maxS;
}

int maxScoreWords(char** words, int wordsSize, char* letters, int lettersSize, int* score, int scoreSize) {
    int count[26] = {0};
    for (int i = 0; i < lettersSize; i++) count[letters[i] - 'a']++;
    return backtrackWords(0, words, wordsSize, count, score);
}