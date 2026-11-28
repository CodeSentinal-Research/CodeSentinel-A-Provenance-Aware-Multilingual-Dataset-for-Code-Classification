#include <stdio.h>

int main() {
    char b[9][10];
    for (int i = 0; i < 9; i++) scanf("%s", b[i]);
    int r[9][10] = {0}, c[9][10] = {0}, x[9][10] = {0};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int v = b[i][j] - '0';
            if (r[i][v] || c[j][v] || x[i / 3 * 3 + j / 3][v]) {
                printf("NO\n");
                return 0;
            }
            r[i][v] = c[j][v] = x[i / 3 * 3 + j / 3][v] = 1;
        }
    }
    printf("YES\n");
    return 0;
}
