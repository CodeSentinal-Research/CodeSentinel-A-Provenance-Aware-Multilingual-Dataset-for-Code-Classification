#include <stdio.h>
#include <string.h>
int main() {
    char s[200005], p[200005];
    scanf("%s %s", s, p);
    int n = strlen(s), m = strlen(p);
    int need[256] = {0}, have[256] = {0};
    int required = 0;
    for(int i=0; i<m; i++) { need[p[i]]++; if(need[p[i]] == 1) required++; }
    int formed = 0, l = 0;
    for(int r=0; r<n; r++) {
        have[s[r]]++;
        if(need[s[r]] > 0 && have[s[r]] == need[s[r]]) formed++;
        if(r - l + 1 > m) {
            have[s[l]]--;
            if(need[s[l]] > 0 && have[s[l]] < need[s[l]]) formed--;
            l++;
        }
        if(formed == required) printf("%d ", l);
    }
    printf("\n");
    return 0;
}
