#include <stdio.h>
#include <string.h>
int main() {
    char s1[200005], s2[200005];
    scanf("%s %s", s1, s2);
    int n = strlen(s1), m = strlen(s2);
    if(m > n) { printf("NO\n"); return 0; }
    int need[256] = {0}, have[256] = {0};
    int required = 0;
    for(int i=0; i<m; i++) { need[s1[i]]++; if(need[s1[i]] == 1) required++; }
    int formed = 0, l = 0;
    for(int r=0; r<n; r++) {
        have[s2[r]]++;
        if(need[s2[r]] > 0 && have[s2[r]] == need[s2[r]]) formed++;
        if(r - l + 1 > m) {
            have[s2[l]]--;
            if(need[s2[l]] > 0 && have[s2[l]] < need[s2[l]]) formed--;
            l++;
        }
        if(formed == required) { printf("YES\n"); return 0; }
    }
    printf("NO\n");
    return 0;
}
