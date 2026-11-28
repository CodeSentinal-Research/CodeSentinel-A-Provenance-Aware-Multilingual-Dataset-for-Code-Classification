#include <stdio.h>
#include <string.h>

int main() {
    char s1[100005], s2[100005];
    scanf("%s%s", s1, s2);
    if (strlen(s1) != strlen(s2)) {
        printf("NO\n");
        return 0;
    }
    int m1[256] = {0}, m2[256] = {0};
    for (int i = 0; s1[i]; i++) {
        if (m1[s1[i]] && m1[s1[i]] != s2[i]) {
            printf("NO\n");
            return 0;
        }
        if (m2[s2[i]] && m2[s2[i]] != s1[i]) {
            printf("NO\n");
            return 0;
        }
        m1[s1[i]] = s2[i];
        m2[s2[i]] = s1[i];
    }
    printf("YES\n");
    return 0;
}
