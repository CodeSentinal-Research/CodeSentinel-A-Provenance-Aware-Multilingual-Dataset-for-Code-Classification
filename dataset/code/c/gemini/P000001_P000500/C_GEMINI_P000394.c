#include <stdio.h>
#include <string.h>

#define MAX_N 10005
char names[MAX_N][64];
char brands[MAX_N][64];

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%63s %63s", names[i], brands[i]);
        }
        char target[64];
        scanf("%63s", target);
        for (int i = 0; i < n; i++) {
            if (strcmp(brands[i], target) == 0) {
                printf("%s\n", names[i]);
            }
        }
    }
    return 0;
}