#include <stdio.h>
#include <string.h>

#define MAX_N 10005
char isbns[MAX_N][64];
char titles[MAX_N][64];

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%63s %63s", isbns[i], titles[i]);
        }
        char target[64];
        scanf("%63s", target);
        int found_idx = -1;
        for (int i = 0; i < n; i++) {
            if (strcmp(isbns[i], target) == 0) {
                found_idx = i;
                break;
            }
        }
        if (found_idx != -1) {
            printf("%s %s\n", isbns[found_idx], titles[found_idx]);
        } else {
            printf("Book Not Found\n");
        }
    }
    return 0;
}