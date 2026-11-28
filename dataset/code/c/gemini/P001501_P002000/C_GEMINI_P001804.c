#include <stdlib.h>
#include <stdbool.h>

bool isSameBSTSeq(int* a, int aSize, int* b, int bSize) {
    if (aSize != bSize) return false;
    if (aSize == 0) return true;
    if (a[0] != b[0]) return false;

    int leftA[1000], rightA[1000], leftB[1000], rightB[1000];
    int laSize = 0, raSize = 0, lbSize = 0, rbSize = 0;

    for (int i = 1; i < aSize; i++) {
        if (a[i] < a[0]) leftA[laSize++] = a[i];
        else rightA[raSize++] = a[i];

        if (b[i] < b[0]) leftB[lbSize++] = b[i];
        else rightB[rbSize++] = b[i];
    }

    return isSameBSTSeq(leftA, laSize, leftB, lbSize) && isSameBSTSeq(rightA, raSize, rightB, rbSize);
}