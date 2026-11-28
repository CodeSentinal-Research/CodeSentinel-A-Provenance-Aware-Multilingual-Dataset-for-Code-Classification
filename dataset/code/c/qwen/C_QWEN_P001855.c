#include <stdio.h>
#include <math.h>
int main() {
    int n; scanf("%d", &n);
    int h = (int)log2(n) + 1;
    int completeNodes = (1 << h) - 1;
    printf("%d\n", completeNodes - n);
    return 0;
}
