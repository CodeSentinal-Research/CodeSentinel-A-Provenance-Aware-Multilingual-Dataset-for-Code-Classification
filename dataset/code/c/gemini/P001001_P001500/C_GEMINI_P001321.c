#include <stdlib.h>
#include <string.h>

char* phoneMap[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrackDigits(char* digits, int idx, char* cur, char** res, int* count) {
    if (digits[idx] == '\0') {
        cur[idx] = '\0';
        res[*count] = strdup(cur);
        (*count)++;
        return;
    }
    char* letters = phoneMap[digits[idx] - '0'];
    for (int i = 0; letters[i]; i++) {
        cur[idx] = letters[i];
        backtrackDigits(digits, idx + 1, cur, res, count);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    int len = strlen(digits);
    if (len == 0) {
        *returnSize = 0;
        return NULL;
    }
    char** res = (char**)malloc(5000 * sizeof(char*));
    char cur[len + 1];
    int count = 0;
    backtrackDigits(digits, 0, cur, res, &count);
    *returnSize = count;
    return res;
}