#include <stdio.h>
#include <string.h>
void rev(char *s, int l, int r) { while(l<r) { char t=s[l]; s[l]=s[r]; s[r]=t; l++; r--; } }
int main() {
    char s[1001]; int k; scanf("%s %d", s, &k);
    int n = strlen(s);
    for(int i=0; i<n; i+=2*k) rev(s, i, (i+k-1 < n-1) ? i+k-1 : n-1);
    printf("%s\n", s);
    return 0;
}
