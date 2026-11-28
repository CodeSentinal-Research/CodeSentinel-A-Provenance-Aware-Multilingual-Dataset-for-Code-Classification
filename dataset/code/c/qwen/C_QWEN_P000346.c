#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return strcmp(*(char**)a, *(char**)b); }
int main() {
    char s[1001]; int n; scanf("%s %d", s, &n);
    char dict[100][101];
    for(int i=0; i<n; i++) scanf("%s", dict[i]);
    qsort(dict, n, sizeof(char*), cmp);
    char best[101] = "";
    for(int i=n-1; i>=0; i--) {
        int j=0, k=0;
        while(s[j] && dict[i][k]) { if(s[j]==dict[i][k]) k++; j++; }
        if(dict[i][k]=='\0' && strlen(dict[i]) > strlen(best)) strcpy(best, dict[i]);
    }
    printf("%s\n", best);
    return 0;
}
