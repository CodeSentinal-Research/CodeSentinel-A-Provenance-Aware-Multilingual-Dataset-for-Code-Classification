#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char* alienOrder(char** words, int wordsSize) {
    bool present[26] = {false};
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = true;
        }
    }

    bool adj[26][26] = {false};
    int inDeg[26] = {0};

    for (int i = 0; i < wordsSize - 1; i++) {
        char* w1 = words[i];
        char* w2 = words[i + 1];
        int len1 = strlen(w1), len2 = strlen(w2);
        int minLen = len1 < len2 ? len1 : len2;
        if (len1 > len2 && strncmp(w1, w2, minLen) == 0) {
            char* empty = (char*)malloc(1);
            empty[0] = '\0';
            return empty;
        }
        for (int j = 0; j < minLen; j++) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a', v = w2[j] - 'a';
                if (!adj[u][v]) {
                    adj[u][v] = true;
                    inDeg[v]++;
                }
                break;
            }
        }
    }

    int q[26];
    int head = 0, tail = 0;
    int totalLetters = 0;
    for (int i = 0; i < 26; i++) {
        if (present[i]) {
            totalLetters++;
            if (inDeg[i] == 0) q[tail++] = i;
        }
    }

    char* res = (char*)malloc(27 * sizeof(char));
    int rSize = 0;

    while (head < tail) {
        int u = q[head++];
        res[rSize++] = 'a' + u;
        for (int v = 0; v < 26; v++) {
            if (adj[u][v]) {
                if (--inDeg[v] == 0) q[tail++] = v;
            }
        }
    }
    res[rSize] = '\0';

    if (rSize == totalLetters) return res;
    res[0] = '\0';
    return res;
}