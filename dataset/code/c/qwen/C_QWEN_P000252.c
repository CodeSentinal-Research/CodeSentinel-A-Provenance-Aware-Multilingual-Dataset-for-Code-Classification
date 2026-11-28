#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; scanf("%s", s);
    int l=0, r=strlen(s)-1, pal=1;
    while(l<r) { if(s[l]!=s[r]) { pal=0; break; } l++; r--; }
    printf("%s\n", pal ? "Yes" : "No");
    return 0;
}
