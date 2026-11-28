#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char strs[10000][101];
    for(int i=0; i<n; i++) scanf("%s", strs[i]);
    for(int i=0; i<n; i++) if(strlen(strs[i])==0) { printf("%d\n", i); return 0; }
    printf("-1\n");
    return 0;
}
