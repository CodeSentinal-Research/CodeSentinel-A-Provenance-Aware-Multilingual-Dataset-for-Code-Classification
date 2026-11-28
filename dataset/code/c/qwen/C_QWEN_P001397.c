#include <stdio.h>
#include <string.h>

int main() {
    char s1[100005], s2[100005];
    fgets(s1, 100005, stdin);
    s1[strchr(s1, '\n') - s1] = 0;
    fgets(s2, 100005, stdin);
    s2[strchr(s2, '\n') - s2] = 0;
    int c1[100005][26] = {0}, c2[100005][26] = {0};
    char *w1 = strtok(s1, " ");
    while (w1) {
        for (int i = 0; w1[i]; i++) c1[0][w1[i] - 'a']++;
        w1 = strtok(NULL, " ");
    }
    char *w2 = strtok(s2, " ");
    while (w2) {
        for (int i = 0; w2[i]; i++) c2[0][w2[i] - 'a']++;
        w2 = strtok(NULL, " ");
    }
    int first = 1;
    for (int i = 0; i < 26; i++) {
        if ((c1[0][i] == 1 && c2[0][i] == 0) || (c1[0][i] == 0 && c2[0][i] == 1)) {
            if (!first) printf(" ");
            printf("%c", i + 'a');
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
