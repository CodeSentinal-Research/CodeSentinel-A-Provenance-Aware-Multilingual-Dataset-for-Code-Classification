#include <stdio.h>
#include <string.h>
int main() {
    char s[200005]; int k;
    scanf("%s %d", s, &k);
    int n = strlen(s);
    int count[256] = {0};
    int l=0, max_freq=0, max_len=0;
    for(int r=0; r<n; r++) {
        count[s[r]]++;
        if(count[s[r]] > max_freq) max_freq = count[s[r]];
        while(r - l + 1 - max_freq > k) { count[s[l]]--; l++; }
        if(r - l + 1 > max_len) max_len = r - l + 1;
    }
    printf("%d\n", max_len);
    return 0;
}
