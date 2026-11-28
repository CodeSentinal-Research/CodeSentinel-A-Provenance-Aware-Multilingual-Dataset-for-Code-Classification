#include <stdio.h>
#include <string.h>

#define MAX_N 10005
char flights[MAX_N][64];
char dests[MAX_N][64];

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%63s %63s", flights[i], dests[i]);
        }
        char target[64];
        scanf("%63s", target);
        for (int i = 0; i < n; i++) {
            if (strcmp(dests[i], target) == 0) {
                printf("%s\n", flights[i]);
            }
        }
    }
    return 0;
}