#include <stdlib.h>

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

int* commonElements(int* A, int* B, int* C, int n1, int n2, int n3, int* returnSize) {
    int minSize = MIN3(n1, n2, n3);
    int* res = (int*)malloc(minSize * sizeof(int));
    *returnSize = 0;
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2 && k < n3) {
        if (A[i] == B[j] && B[j] == C[k]) {
            if (*returnSize == 0 || res[*returnSize - 1] != A[i]) {
                res[(*returnSize)++] = A[i];
            }
            i++; j++; k++;
        } else if (A[i] < B[j]) {
            i++;
        } else if (B[j] < C[k]) {
            j++;
        } else {
            k++;
        }
    }
    return res;
}