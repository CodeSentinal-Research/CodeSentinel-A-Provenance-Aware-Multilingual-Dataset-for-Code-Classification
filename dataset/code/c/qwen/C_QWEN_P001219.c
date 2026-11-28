#include <stdio.h>
#include <string.h>
char dict[10001][101];
char res[100000][1001];
int r_idx = 0;
void solve(char *s, int idx, char *curr, int c_idx) {
    if(s[idx] == '\0') { curr[c_idx] = '\0'; strcpy(res[r_idx++], curr); return; }
    for(int i=0; dict[i][0]; i++) {
        int len = strlen(dict[i]);
        if(strncmp(s+idx, dict[i], len) == 0) {
            int new_idx = c_idx;
            if(c_idx > 0) curr[new_idx++] = ' ';
            strcpy(curr+new_idx, dict[i]);
            solve(s, idx+len, curr, new_idx+len);
        }
    }
}
int main() {
    char s[101]; scanf("%s", s);
    int m; scanf("%d", &m);
    for(int i=0; i<m; i++) scanf("%s", dict[i]);
    dict[m][0] = '\0';
    char curr[1001];
    solve(s, 0, curr, 0);
    for(int i=0; i<r_idx; i++) printf("%s\n", res[i]);
    return 0;
}
