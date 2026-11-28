#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char queries[n][101];
    for (int i = 0; i < n; i++) scanf("%s", queries[i]);
    char pattern[101];
    scanf("%s", pattern);
    
    for (int i = 0; i < n; i++) {
        int j = 0, k = 0;
        while (j < strlen(queries[i])) {
            if (k < strlen(pattern) && queries[i][j] == pattern[k]) { j++; k++; }
            else if (queries[i][j] >= 'A' && queries[i][j] <= 'Z') break;
            else j++;
        }
        printf("%s\n", k == strlen(pattern) ? "YES" : "NO");
    }
    return 0;
}
