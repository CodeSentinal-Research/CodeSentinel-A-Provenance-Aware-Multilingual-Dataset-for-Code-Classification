#include <stdio.h>

void printFloydTriangle(int rows) {
    int num = 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d%s", num++, (j == i ? "" : " "));
        }
        printf("\n");
    }
}

int main() {
    int rows;
    if (scanf("%d", &rows) == 1) {
        printFloydTriangle(rows);
    }
    return 0;
}