#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool diffByOne(const char* a, const char* b) {
    int diff = 0;
    for (int i = 0; a[i]; i++) {
        if (a[i] != b[i]) {
            diff++;
            if (diff > 1) return false;
        }
    }
    return diff == 1;
}

int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    int endIdx = -1;
    for (int i = 0; i < wordListSize; i++) {
        if (strcmp(wordList[i], endWord) == 0) { endIdx = i; break; }
    }
    if (endIdx == -1) return 0;

    bool* vis = (bool*)calloc(wordListSize, sizeof(bool));
    int* q = (int*)malloc((wordListSize + 1) * sizeof(int));
    int* dist = (int*)malloc((wordListSize + 1) * sizeof(int));
    int head = 0, tail = 0;

    for (int i = 0; i < wordListSize; i++) {
        if (diffByOne(beginWord, wordList[i])) {
            vis[i] = true;
            q[tail] = i;
            dist[tail++] = 2;
        }
    }

    int ans = 0;
    while (head < tail) {
        int u = q[head];
        int d = dist[head++];
        if (u == endIdx) { ans = d; break; }
        for (int v = 0; v < wordListSize; v++) {
            if (!vis[v] && diffByOne(wordList[u], wordList[v])) {
                vis[v] = true;
                q[tail] = v;
                dist[tail++] = d + 1;
            }
        }
    }
    free(vis);
    free(q);
    free(dist);
    return ans;
}