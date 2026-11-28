#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(char *)b - *(char *)a;
}

int main() {
    char s[200005];
    scanf("%s", s);
    qsort(s, strlen(s), sizeof(char), cmp);
    printf("%s\n", s);
    return 0;
}
