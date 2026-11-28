#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 100005
int vals[MAX_N];
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
    char s[32];
    int cnt = 0;
    while (scanf("%31s", s) == 1) {
        if (strcmp(s, "null") != 0 && strcmp(s, "#") != 0 && strcmp(s, "N") != 0) {
            vals[cnt++] = atoi(s);
        }
    }
    qsort(vals, cnt, sizeof(int), cmp);
    for (int i = 0; i < cnt; i++) printf("%d%s", vals[i], i == cnt - 1 ? "" : " ");
    printf("\n");
    return 0;
}