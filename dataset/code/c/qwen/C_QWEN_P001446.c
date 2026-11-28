#include <stdio.h>
#include <string.h>

int main() {
    char s1[100001], s2[100001];
    scanf("%s %s", s1, s2);
    int p;
    scanf("%d", &p);
    char pairs[p][2][101];
    for (int i = 0; i < p; i++) scanf("%s %s", pairs[i][0], pairs[i][1]);
    
    char *w1 = strtok(s1, " ");
    char *w2 = strtok(s2, " ");
    int similar = 1;
    while (w1 && w2) {
        if (strcmp(w1, w2) != 0) {
            int found = 0;
            for (int i = 0; i < p; i++) {
                if ((strcmp(w1, pairs[i][0]) == 0 && strcmp(w2, pairs[i][1]) == 0) ||
                    (strcmp(w1, pairs[i][1]) == 0 && strcmp(w2, pairs[i][0]) == 0)) {
                    found = 1;
                    break;
                }
            }
            if (!found) { similar = 0; break; }
        }
        w1 = strtok(NULL, " ");
        w2 = strtok(NULL, " ");
    }
    printf("%s\n", similar ? "YES" : "NO");
    return 0;
}
