#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char words[n][10005];
    int count[n][26];
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
        memset(count[i], 0, sizeof(count[i]));
        for (int j = 0; words[i][j]; j++) {
            count[i][words[i][j] - 'a']++;
        }
    }
    int res[26];
    for (int i = 0; i < 26; i++) res[i] = count[0][i];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (count[i][j] < res[j]) res[j] = count[i][j];
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < res[i]; j++) {
            printf("%c", i + 'a');
        }
    }
    printf("\n");
    return 0;
}
