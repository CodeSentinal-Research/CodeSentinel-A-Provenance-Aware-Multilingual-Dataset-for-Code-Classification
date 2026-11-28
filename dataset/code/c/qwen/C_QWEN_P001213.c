#include <stdio.h>
#include <string.h>
int memo[101][101][101][101];
int solve(char *s1, char *s2, int i, int j, int len) {
    if(len <= 0) return 1;
    if(len == 1) return s1[i] == s2[j];
    if(memo[i][j][len][0] != -1) return memo[i][j][len][0]; // simplified
    for(int k=1; k<len; k++) {
        if((solve(s1, s2, i, j, k) && solve(s1, s2, i+k, j+k, len-k)) ||
           (solve(s1, s2, i, j+len-k, k) && solve(s1, s2, i+k, j, len-k))) {
            return 1;
        }
    }
    return 0;
}
int main() {
    char s1[101], s2[101]; scanf("%s%s", s1, s2);
    int n = strlen(s1);
    printf("%s\n", solve(s1, s2, 0, 0, n) ? "YES" : "NO");
    return 0;
}
