#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return strcmp(*(char**)a, *(char**)b); }
int main() {
    int n; scanf("%d", &n);
    char strs[100][201], sorted[100][201];
    for(int i=0; i<n; i++) { scanf("%s", strs[i]); strcpy(sorted[i], strs[i]); qsort(sorted[i], strlen(sorted[i]), sizeof(char), cmp); }
    int printed[100]={0};
    for(int i=0; i<n; i++) {
        if(printed[i]) continue;
        printf("["); int first=1;
        for(int j=i; j<n; j++) {
            if(strcmp(sorted[i], sorted[j])==0) { if(!first) printf(", "); printf("%s", strs[j]); printed[j]=1; first=0; }
        }
        printf("]\n");
    }
    return 0;
}
