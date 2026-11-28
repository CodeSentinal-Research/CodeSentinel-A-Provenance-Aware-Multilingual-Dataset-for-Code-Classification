#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 10005
char names[MAX_N][64];
char depts[MAX_N][64];

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%63s %63s", names[i], depts[i]);
        }
        char target[64];
        scanf("%63s", target);
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (strcmp(depts[i], target) == 0) {
                printf("%s\n", names[i]);
                found = true;
            }
        }
        if (!found) {
            printf("No Records Found\n");
        }
    }
    return 0;
}