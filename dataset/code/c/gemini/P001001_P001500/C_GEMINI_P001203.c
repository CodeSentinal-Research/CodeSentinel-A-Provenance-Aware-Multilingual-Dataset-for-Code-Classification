#include <stdlib.h>

typedef struct {
    int w, h;
} Env;

int cmpEnv(const void* a, const void* b) {
    Env* e1 = (Env*)a;
    Env* e2 = (Env*)b;
    if (e1->w != e2->w) return e1->w - e2->w;
    return e2->h - e1->h;
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize) {
    if (envelopesSize == 0) return 0;
    Env* arr = (Env*)malloc(envelopesSize * sizeof(Env));
    for (int i = 0; i < envelopesSize; i++) {
        arr[i].w = envelopes[i][0];
        arr[i].h = envelopes[i][1];
    }
    qsort(arr, envelopesSize, sizeof(Env), cmpEnv);

    int tails[envelopesSize];
    int size = 0;

    for (int k = 0; k < envelopesSize; k++) {
        int h = arr[k].h;
        int l = 0, r = size;
        while (l < r) {
            int m = (l + r) / 2;
            if (tails[m] < h) l = m + 1;
            else r = m;
        }
        tails[l] = h;
        if (l == size) size++;
    }
    free(arr);
    return size;
}