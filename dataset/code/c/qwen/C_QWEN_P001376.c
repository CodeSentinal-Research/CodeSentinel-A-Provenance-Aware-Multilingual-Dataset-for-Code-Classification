#include <stdio.h>
#include <string.h>

int main() {
    char p[305], s[100005];
    scanf("%s", p);
    fgets(s, 100005, stdin);
    s[strchr(s, '\n') - s] = 0;
    char *words[100005];
    int nw = 0;
    words[nw++] = strtok(s, " ");
    while (words[nw - 1]) words[nw++] = strtok(NULL, " ");
    nw--;
    if (nw != strlen(p)) {
        printf("NO\n");
        return 0;
    }
    int m1[256] = {0}, m2[100005] = {0};
    for (int i = 0; i < nw; i++) {
        if (m1[p[i]] && strcmp(words[m1[p[i]] - 1], words[i]) != 0) {
            printf("NO\n");
            return 0;
        }
        if (m2[i] && p[m2[i] - 1] != p[i]) {
            printf("NO\n");
            return 0;
        }
        m1[p[i]] = i + 1;
        m2[i] = i + 1;
    }
    printf("YES\n");
    return 0;
}
