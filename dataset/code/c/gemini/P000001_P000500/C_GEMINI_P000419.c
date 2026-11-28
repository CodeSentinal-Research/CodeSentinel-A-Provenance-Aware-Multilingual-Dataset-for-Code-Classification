#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            char dev[64], st[64];
            scanf("%63s %63s", dev, st);
            char lower[64];
            for (int j = 0; st[j]; j++) lower[j] = tolower(st[j]);
            lower[strlen(st)] = '\0';
            if (strcmp(lower, "online") == 0 || strcmp(lower, "active") == 0 || strcmp(lower, "true") == 0 || strcmp(lower, "1") == 0 || strcmp(lower, "yes") == 0) {
                printf("%s\n", dev);
            }
        }
    }
    return 0;
}