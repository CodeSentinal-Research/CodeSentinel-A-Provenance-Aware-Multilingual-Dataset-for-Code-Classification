#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int cmp(const void* a, const void* b) { return (*(char*)a - *(char*)b); }
bool is_scramble(char* s1, char* s2, int len) {
    if (strncmp(s1, s2, len) == 0) return true;
    char t1[32], t2[32];
    strncpy(t1, s1, len); t1[len] = '\0';
    strncpy(t2, s2, len); t2[len] = '\0';
    qsort(t1, len, sizeof(char), cmp);
    qsort(t2, len, sizeof(char), cmp);
    if (strcmp(t1, t2) != 0) return false;
    for (int i = 1; i < len; i++) {
        if ((is_scramble(s1, s2, i) && is_scramble(s1 + i, s2 + i, len - i)) ||
            (is_scramble(s1, s2 + len - i, i) && is_scramble(s1 + i, s2, len - i))) {
            return true;
        }
    }
    return false;
}
int main() {
    char s1[64], s2[64];
    if (scanf("%63s %63s", s1, s2) == 2) {
        if (strlen(s1) != strlen(s2)) printf("false\n");
        else printf("%s\n", is_scramble(s1, s2, strlen(s1)) ? "true" : "false");
    }
    return 0;
}