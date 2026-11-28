#include <stdio.h>

int parentIndex(int i) {
    if (i <= 0) return -1;
    return (i - 1) / 2;
}

int main() {
    int i;
    if (scanf("%d", &i) == 1) {
        printf("%d\n", parentIndex(i));
    }
    return 0;
}