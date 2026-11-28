#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int rank_arr[26];

int cmp(const void* a, const void* b) {
    char c1 = *(const char*)a;
    char c2 = *(const char*)b;
    return rank_arr[c1 - 'a'] - rank_arr[c2 - 'a'];
}

int main() {
    char order[105], s[1005];
    if (scanf("%104s %1004s", order, s) == 2) {
        for (int i = 0; i < 26; i++) rank_arr[i] = 1000;
        int olen = strlen(order);
        for (int i = 0; i < olen; i++) rank_arr[order[i] - 'a'] = i;
        qsort(s, strlen(s), sizeof(char), cmp);
        printf("%s\n", s);
    }
    return 0;
}