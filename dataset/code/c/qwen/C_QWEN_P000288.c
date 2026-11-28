#include <stdio.h>
#include <string.h>
int isPal(char *s, int l, int r) { while(l<r) { if(s[l]!=s[r]) return 0; l++; r--; } return 1; }
int main() {
    char s[1001]; scanf("%s", s);
    int l=0, r=strlen(s)-1;
    while(l<r) {
        if(s[l]!=s[r]) { printf("%s\n", isPal(s, l+1, r) || isPal(s, l, r-1) ? "Yes" : "No"); return 0; }
        l++; r--;
    }
    printf("Yes\n");
    return 0;
}
