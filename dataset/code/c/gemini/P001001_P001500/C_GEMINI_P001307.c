#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* police = (int*)malloc(n * sizeof(int));
        int* thieves = (int*)malloc(n * sizeof(int));
        int pCount = 0, tCount = 0;

        for (int i = 0; i < n; i++) {
            char ch;
            scanf(" %c", &ch);
            if (ch == 'P') police[pCount++] = i;
            else thieves[tCount++] = i;
        }

        int pIdx = 0, tIdx = 0, caught = 0;
        while (pIdx < pCount && tIdx < tCount) {
            if (abs(police[pIdx] - thieves[tIdx]) <= k) {
                caught++;
                pIdx++;
                tIdx++;
            } else if (police[pIdx] < thieves[tIdx]) {
                pIdx++;
            } else {
                tIdx++;
            }
        }
        printf("%d\n", caught);
        free(police);
        free(thieves);
    }
    return 0;
}