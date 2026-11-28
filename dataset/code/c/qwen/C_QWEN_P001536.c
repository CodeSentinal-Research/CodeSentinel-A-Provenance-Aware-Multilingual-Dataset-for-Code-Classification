#include <stdio.h>
#include <string.h>
int main() {
    char s[200005], t[200005];
    scanf("%s %s", s, t);
    int n = strlen(s), m = strlen(t);
    int need[256] = {0}, have[256] = {0};
    int required = 0;
    for(int i=0; i<m; i++) { need[t[i]]++; if(need[t[i]] == 1) required++; }
    int formed = 0, l = 0, min_len = 1e9, start = -1;
    for(int r=0; r<n; r++) {
        have[s[r]]++;
        if(need[s[r]] > 0 && have[s[r]] == need[s[r]]) formed++;
        while(formed == required) {
            if(r - l + 1 < min_len) { min_len = r - l + 1; start = l; }
            have[s[l]]--;
            if(need[s[l]] > 0 && have[s[l]] < need[s[l]]) formed--;
            l++;
        }
    }
    if(start == -1) printf("\n");
    else {
        char res[200005];
        strncpy(res, s+start, min_len);
        res[min_len] = '\0';
        printf("%s\n", res);
    }
    return 0;
}
