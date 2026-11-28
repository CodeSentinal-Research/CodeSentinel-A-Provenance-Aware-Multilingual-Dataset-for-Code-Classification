#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            char room[64], status[64];
            scanf("%63s %63s", room, status);
            char lower[64];
            for (int j = 0; status[j]; j++) lower[j] = tolower(status[j]);
            lower[strlen(status)] = '\0';
            if (strcmp(lower, "available") == 0 || strcmp(lower, "true") == 0 || strcmp(lower, "1") == 0 || strcmp(lower, "yes") == 0 || strcmp(lower, "free") == 0) {
                printf("%s\n", room);
            }
        }
    }
    return 0;
}