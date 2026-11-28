#include <stdio.h>
#include <string.h>
int main() {
    char a[1001], b[1001]; scanf("%s %s", a, b);
    int n = strlen(a);
    for(int i=0; i<=n; i++) {
        char s1[1001], s2[1001];
        strncpy(s1, a, i); s1[i]='\0'; strcpy(s1+i, b+n-i);
        strncpy(s2, b, i); s2[i]='\0'; strcpy(s2+i, a+n-i);
        // check palindrome
        int p1=1, p2=1;
        for(int l=0, r=n-1; l<r; l++, r--) { if(s1[l]!=s1[r]) p1=0; if(s2[l]!=s2[r]) p2=0; }
        if(p1 || p2) { printf("Yes\n"); return 0; }
    }
    printf("No\n");
    return 0;
}
