#include <stdio.h>
#include <string.h>

int n;
char s[100001];
int count[26] = {0}, avail[26] = {0};
int max_s = 0;

void gen(int i, int s) {
    if (s > max_s) max_s = s;
    if (i == n) return;
    gen(i + 1, s);
    int ok = 1;
    int ws[26] = {0};
    for (int j = 0; s[i][j]; j++) {
        ws[s[i][j] - 'a']++;
        if (ws[s[i][j] - 'a'] > avail[s[i][j] - 'a']) {
            ok = 0;
            break;
        }
    }
    if (ok) {
        for (int j = 0; j < 26; j++) avail[j] -= ws[j];
        int ws_score = 0;
        for (int j = 0; s[i][j]; j++) ws_score += count[s[i][j] - 'a'];
        gen(i + 1, s + ws_score);
        for (int j = 0; j < 26; j++) avail[j] += ws[j];
    }
}

int main() {
    scanf("%d", &n);
    char words[15][20];
    for (int i = 0; i < n; i++) scanf("%s", words[i]);
    char av[30];
    scanf("%s", av);
    for (int i = 0; av[i]; i++) avail[av[i] - 'a']++;
    for (int i = 0; i < 26; i++) scanf("%d", &count[i]);
    gen(0, 0);
    printf("%d\n", max_s);
    return 0;
}
