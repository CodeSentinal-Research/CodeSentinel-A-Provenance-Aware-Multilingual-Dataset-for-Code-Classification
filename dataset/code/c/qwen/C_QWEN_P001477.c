#include <stdio.h>
#include <string.h>

void process(char *s, char *res) {
    int idx = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '#') { if (idx > 0) idx--; }
        else res[idx++] = s[i];
    }
    res[idx] = '\0';
}

int main() {
    char s[200001], t[200001];
    scanf("%s %s", s, t);
    char rs[200001], rt[200001];
    process(s, rs);
    process(t, rt);
    printf("%s\n", strcmp(rs, rt) == 0 ? "YES" : "NO");
    return 0;
}
