#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_N 10005
char names[MAX_N][64], depts[MAX_N][64], statuses[MAX_N][64];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%63s %63s %63s", names[i], depts[i], statuses[i]);
        char target[64];
        scanf("%63s", target);
        for (int i = 0; i < n; i++) {
            char lower[64];
            for (int j = 0; statuses[i][j]; j++) lower[j] = tolower(statuses[i][j]);
            lower[strlen(statuses[i])] = '\0';
            if (strcmp(depts[i], target) == 0 && (strcmp(lower, "active") == 0 || strcmp(lower, "true") == 0 || strcmp(lower, "1") == 0 || strcmp(lower, "yes") == 0)) {
                printf("%s\n", names[i]);
            }
        }
    }
    return 0;
}