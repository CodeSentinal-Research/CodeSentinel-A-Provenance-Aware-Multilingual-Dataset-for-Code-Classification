#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char words[n][101];
    for (int i = 0; i < n; i++) scanf("%s", words[i]);
    
    char order[27];
    scanf("%s", order);
    
    int rank[256] = {0};
    for (int i = 0; order[i]; i++) rank[order[i]] = i;
    
    int sorted = 1;
    for (int i = 0; i < n - 1; i++) {
        int min_len = strlen(words[i]) < strlen(words[i+1]) ? strlen(words[i]) : strlen(words[i+1]);
        int cmp = 0;
        for (int j = 0; j < min_len; j++) {
            if (rank[words[i][j]] < rank[words[i+1][j]]) { cmp = -1; break; }
            if (rank[words[i][j]] > rank[words[i+1][j]]) { cmp = 1; break; }
        }
        if (cmp == 0 && strlen(words[i]) > strlen(words[i+1])) cmp = 1;
        if (cmp > 0) { sorted = 0; break; }
    }
    printf("%s\n", sorted ? "YES" : "NO");
    return 0;
}
