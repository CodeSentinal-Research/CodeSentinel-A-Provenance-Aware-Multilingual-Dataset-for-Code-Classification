#include <stdio.h>
#include <string.h>

#define MAX_N 10005
char trains[MAX_N][64];
char names[MAX_N][64];

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%63s %63s", trains[i], names[i]);
        }
        char target[64];
        scanf("%63s", target);
        int found_idx = -1;
        for (int i = 0; i < n; i++) {
            if (strcmp(trains[i], target) == 0) {
                found_idx = i;
                break;
            }
        }
        if (found_idx != -1) {
            printf("%s %s\n", trains[found_idx], names[found_idx]);
        } else {
            printf("Train Not Found\n");
        }
    }
    return 0;
}