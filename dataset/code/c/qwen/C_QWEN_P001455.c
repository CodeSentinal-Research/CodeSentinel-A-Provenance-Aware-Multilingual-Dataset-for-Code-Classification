#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);
    int n = strlen(s);
    
    int max_len = -1;
    char ans[100001] = "";
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int len = j - i;
            if (len > max_len) {
                // Check if substring s[i..j-1] appears again
                char sub[100001];
                strncpy(sub, s + i, len);
                sub[len] = '\0';
                
                int found = 0;
                for (int k = i + 1; k + len <= n; k++) {
                    if (strncmp(s + k, sub, len) == 0) { found = 1; break; }
                }
                if (found) {
                    max_len = len;
                    strcpy(ans, sub);
                }
            }
        }
    }
    printf("%s\n", max_len == -1 ? "" : ans);
    return 0;
}
