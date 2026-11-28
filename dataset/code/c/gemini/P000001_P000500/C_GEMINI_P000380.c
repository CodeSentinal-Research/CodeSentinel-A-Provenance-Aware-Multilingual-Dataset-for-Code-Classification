#include <stdio.h>
#include <string.h>

#define MAX_N 10005
char hids[MAX_N][64];
char names[MAX_N][64];

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%63s %63s", hids[i], names[i]);
        }
        char target[64];
        scanf("%63s", target);
        int found_idx = -1;
        for (int i = 0; i < n; i++) {
            if (strcmp(hids[i], target) == 0) {
                found_idx = i;
                break;
            }
        }
        if (found_idx != -1) {
            printf("%s %s\n", hids[found_idx], names[found_idx]);
        } else {
            printf("Hotel Not Found\n");
        }
    }
    return 0;
}