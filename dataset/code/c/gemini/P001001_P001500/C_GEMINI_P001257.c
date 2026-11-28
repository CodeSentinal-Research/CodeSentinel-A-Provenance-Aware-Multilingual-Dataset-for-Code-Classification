#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int* partitionLabels(char* s, int* returnSize) {
    int n = strlen(s);
    int last[26];
    for (int i = 0; i < n; i++) last[s[i] - 'a'] = i;

    int* res = (int*)malloc(n * sizeof(int));
    int count = 0;
    int anchor = 0, j = 0;

    for (int i = 0; i < n; i++) {
        j = MAX(j, last[s[i] - 'a']);
        if (i == j) {
            res[count++] = i - anchor + 1;
            anchor = i + 1;
        }
    }
    *returnSize = count;
    return res;
}