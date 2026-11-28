#include <stdio.h>
#include <string.h>
void solve(char *s, int idx, int parts, char *curr, int c_idx, char res[][20], int *r_idx) {
    if(parts == 4 && s[idx] == '\0') { curr[c_idx] = '\0'; strcpy(res[(*r_idx)++], curr); return; }
    if(parts >= 4) return;
    int num = 0;
    for(int i=idx; i<idx+3 && s[i]; i++) {
        num = num*10 + (s[i]-'0');
        if(num > 255) break;
        int len = sprintf(curr+c_idx, "%s%d", parts>0?".":"", num);
        solve(s, i+1, parts+1, curr, c_idx+len, res, r_idx);
        if(num == 0) break;
    }
}
int main() {
    char s[20]; scanf("%s", s);
    char res[100][20]; int r_idx = 0; char curr[20];
    solve(s, 0, 0, curr, 0, res, &r_idx);
    for(int i=0; i<r_idx; i++) printf("%s\n", res[i]);
    return 0;
}
