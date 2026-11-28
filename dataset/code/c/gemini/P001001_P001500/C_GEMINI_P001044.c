#include <stdio.h>
#include <math.h>

int nodeLevel(int idx) {
    return (int)log2(idx + 1);
}

int main() {
    int idx;
    if (scanf("%d", &idx) == 1) {
        printf("%d\n", nodeLevel(idx));
    }
    return 0;
}