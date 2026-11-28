#include <stdio.h>
#include <string.h>

#define MAX_N 10005
char tids[MAX_N][64];
char details[MAX_N][64];

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%63s %63s", tids[i], details[i]);
        }
        char target[64];
        scanf("%63s", target);
        int found_idx = -1;
        for (int i = 0; i < n; i++) {
            if (strcmp(tids[i], target) == 0) {
                found_idx = i;
                break;
            }
        }
        if (found_idx != -1) {
            printf("%s %s\n", tids[found_idx], details[found_idx]);
        } else {
            printf("Transaction Not Found\n");
        }
    }
    return 0;
}