#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[100005];
    int count[256] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int j = 0; s[j]; j++) count[s[j]]++;
    }
    char res = '-';
    for (int i = 0; s[i]; i++) {
        if (count[s[i]] == 1) {
            res = s[i];
            break;
        }
    }
    printf("%c\n", res);
    return 0;
}
