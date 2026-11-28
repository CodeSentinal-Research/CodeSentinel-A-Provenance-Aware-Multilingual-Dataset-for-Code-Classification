#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(char*)a - *(char*)b; }
int main() {
    char s[1001]; scanf("%s", s);
    qsort(s, strlen(s), sizeof(char), cmp);
    printf("%s\n", s);
    return 0;
}
