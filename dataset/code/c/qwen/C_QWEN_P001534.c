#include <stdio.h>
#include <string.h>
int main() {
    char s[200005];
    scanf("%s", s);
    int n = strlen(s);
    int max_len = 0, l = 0, distinct = 0;
    int count[256] = {0};
    for(int r=0; r<n; r++) {
        if(count[s[r]] == 0) distinct++;
        count[s[r]]++;
        while(distinct > 2) {
            count[s[l]]--;
            if(count[s[l]] == 0) distinct--;
            l++;
        }
        if(r - l + 1 > max_len) max_len = r - l + 1;
    }
    printf("%d\n", max_len);
    return 0;
}
