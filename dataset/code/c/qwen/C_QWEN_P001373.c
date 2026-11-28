#include <stdio.h>
#include <string.h>

int main() {
    char s1[100005], s2[100005];
    scanf("%s%s", s1, s2);
    if (strlen(s1) != strlen(s2)) {
        printf("NO\n");
        return 0;
    }
    int c1[256] = {0}, c2[256] = {0};
    for (int i = 0; s1[i]; i++) {
        c1[s1[i]]++;
        c2[s2[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (c1[i] != c2[i]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
