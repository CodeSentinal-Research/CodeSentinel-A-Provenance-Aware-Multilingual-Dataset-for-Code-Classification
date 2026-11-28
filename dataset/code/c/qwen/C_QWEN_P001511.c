#include <stdio.h>
#include <string.h>
int main() {
    char s[200005]; int k;
    scanf("%s %d", s, &k);
    int n = strlen(s);
    int max_len = 0;
    for(char c='T'; c<='F'; c++) {
        int l=0, count=0;
        for(int r=0; r<n; r++) {
            if(s[r] != c) count++;
            while(count > k) { if(s[l] != c) count--; l++; }
            if(r - l + 1 > max_len) max_len = r - l + 1;
        }
    }
    printf("%d\n", max_len);
    return 0;
}
