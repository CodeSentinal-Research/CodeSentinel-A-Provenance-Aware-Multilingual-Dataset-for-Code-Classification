#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char words[n][101];
    for (int i = 0; i < n; i++) scanf("%s", words[i]);
    
    char pattern[101];
    scanf("%s", pattern);
    
    for (int i = 0; i < n; i++) {
        if (strlen(words[i]) != strlen(pattern)) continue;
        int map_w[256] = {0}, map_p[256] = {0};
        int valid = 1;
        for (int j = 0; pattern[j]; j++) {
            if (map_w[words[i][j]] && map_w[words[i][j]] != pattern[j]) { valid = 0; break; }
            if (map_p[pattern[j]] && map_p[pattern[j]] != words[i][j]) { valid = 0; break; }
            map_w[words[i][j]] = pattern[j];
            map_p[pattern[j]] = words[i][j];
        }
        if (valid) printf("%s\n", words[i]);
    }
    return 0;
}
