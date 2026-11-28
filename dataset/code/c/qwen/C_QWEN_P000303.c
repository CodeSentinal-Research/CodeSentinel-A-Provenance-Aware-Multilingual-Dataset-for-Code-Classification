#include <stdio.h>
#include <string.h>
char dict[1000][101]; int n;
void solve(char *s, int idx, char *curr, int c_idx) {
    if(s[idx] == '\0') { curr[c_idx] = '\0'; printf("%s\n", curr); return; }
    for(int i=0; i<n; i++) {
        int l = strlen(dict[i]);
        if(strncmp(s+idx, dict[i], l) == 0) {
            int len = sprintf(curr+c_idx, "%s%s", c_idx>0?" ":"", dict[i]);
            solve(s, idx+l, curr, c_idx+len);
        }
    }
}
int main() {
    char s[101]; scanf("%s %d", s, &n);
    for(int i=0; i<n; i++) scanf("%s", dict[i]);
    char curr[1001];
    solve(s, 0, curr, 0);
    return 0;
}
