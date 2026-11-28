#include <stdio.h>
#include <string.h>
int main() {
    char s[200005];
    scanf("%s", s);
    int n = strlen(s);
    int max_len = 0, l = 0;
    int last[256];
    for(int i=0; i<256; i++) last[i] = -1;
    for(int r=0; r<n; r++) {
        if(last[s[r]] >= l) l = last[s[r]] + 1;
        last[s[r]] = r;
        if(r - l + 1 > max_len) max_len = r - l + 1;
    }
    printf("%d\n", max_len);
    return 0;
}
