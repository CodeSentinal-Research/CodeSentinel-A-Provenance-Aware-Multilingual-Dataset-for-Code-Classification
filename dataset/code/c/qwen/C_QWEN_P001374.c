#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char words[100005][25];
int n;

int cmp(const void *a, const void *b) {
    char s1[25], s2[25];
    strcpy(s1, words[*(int *)a]);
    strcpy(s2, words[*(int *)b]);
    int l1 = strlen(s1), l2 = strlen(s2);
    if (l1 != l2) return l1 - l2;
    return strcmp(s1, s2);
}

int main() {
    scanf("%d", &n);
    int idx[n];
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
        idx[i] = i;
    }
    qsort(idx, n, sizeof(int), cmp);
    for (int i = 0; i < n;) {
        printf("%s", words[idx[i]]);
        int j = i + 1;
        while (j < n && strcmp(words[idx[i]], words[idx[j]]) == 0) {
            printf(" %s", words[idx[j]]);
            j++;
        }
        printf("\n");
        i = j;
    }
    return 0;
}
