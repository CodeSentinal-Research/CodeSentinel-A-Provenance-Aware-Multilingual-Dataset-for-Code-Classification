#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char strs[10000][101]; int min_len=1000000, idx=0;
    for(int i=0; i<n; i++) { scanf("%s", strs[i]); if(strlen(strs[i])<min_len) { min_len=strlen(strs[i]); idx=i; } }
    printf("%d\n", idx);
    return 0;
}
