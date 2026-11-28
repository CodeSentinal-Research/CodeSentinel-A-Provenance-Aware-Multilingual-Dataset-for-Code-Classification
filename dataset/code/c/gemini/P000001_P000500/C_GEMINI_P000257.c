#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(char*)a - *(char*)b; }
int main() {
    char s1[1000], s2[1000];
    if (scanf("%999s %999s", s1, s2) == 2) {
        qsort(s1, strlen(s1), 1, cmp);
        qsort(s2, strlen(s2), 1, cmp);
        printf("%s\n", strcmp(s1, s2) == 0 ? "Anagram" : "Not Anagram");
    }
    return 0;
}