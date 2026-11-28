#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; char c; scanf("%s %c", s, &c);
    int n = strlen(s), res[1001];
    int prev = -10000;
    for(int i=0; i<n; i++) { if(s[i]==c) prev=i; res[i] = i-prev; }
    prev = 10000;
    for(int i=n-1; i>=0; i--) { if(s[i]==c) prev=i; if(prev-i < res[i]) res[i] = prev-i; }
    for(int i=0; i<n; i++) printf("%d%c", res[i], i==n-1?'\n':' ');
    return 0;
}
