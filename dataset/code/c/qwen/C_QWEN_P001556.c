#include <stdio.h>
#include <string.h>
int main() {
    char text[200005], pattern[200005];
    scanf("%s %s", text, pattern);
    int n = strlen(text), m = strlen(pattern);
    int need[256] = {0}, have[256] = {0};
    int required = 0;
    for(int i=0; i<m; i++) { need[pattern[i]]++; if(need[pattern[i]] == 1) required++; }
    int formed = 0, l = 0, count = 0;
    for(int r=0; r<n; r++) {
        have[text[r]]++;
        if(need[text[r]] > 0 && have[text[r]] == need[text[r]]) formed++;
        if(r - l + 1 > m) {
            have[text[l]]--;
            if(need[text[l]] > 0 && have[text[l]] < need[text[l]]) formed--;
            l++;
        }
        if(formed == required) count++;
    }
    printf("%d\n", count);
    return 0;
}
