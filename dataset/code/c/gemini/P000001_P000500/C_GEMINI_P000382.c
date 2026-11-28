#include <stdio.h>
#include <string.h>

#define MAX_N 10005
char unames[MAX_N][64];
char emails[MAX_N][64];

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%63s %63s", unames[i], emails[i]);
        }
        char target[64];
        scanf("%63s", target);
        int found_idx = -1;
        for (int i = 0; i < n; i++) {
            if (strcmp(unames[i], target) == 0) {
                found_idx = i;
                break;
            }
        }
        if (found_idx != -1) {
            printf("%s\n", emails[found_idx]);
        } else {
            printf("User Not Found\n");
        }
    }
    return 0;
}