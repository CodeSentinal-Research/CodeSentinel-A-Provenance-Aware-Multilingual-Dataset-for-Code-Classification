#include <stdio.h>
#include <string.h>
int main() {
    char s[200005];
    scanf("%s", s);
    int n = strlen(s);
    int max_len = 1, l = 0, adj = 0;
    for(int r=1; r<n; r++) {
        if(s[r] == s[r-1]) adj++;
        while(adj > 1) { if(s[l] == s[l+1]) adj--; l++; }
        if(r - l + 1 > max_len) max_len = r - l + 1;
    }
    printf("%d\n", max_len);
    return 0;
}
