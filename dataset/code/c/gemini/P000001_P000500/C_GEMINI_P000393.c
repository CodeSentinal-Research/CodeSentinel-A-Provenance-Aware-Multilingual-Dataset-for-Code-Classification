#include <stdio.h>
#include <string.h>

#define MAX_N 10005
char names[MAX_N][64];

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%63s", names[i]);
        }
        char prefix[64];
        scanf("%63s", prefix);
        int plen = strlen(prefix);
        for (int i = 0; i < n; i++) {
            if (strncmp(names[i], prefix, plen) == 0) {
                printf("%s\n", names[i]);
            }
        }
    }
    return 0;
}