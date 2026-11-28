#include <stdio.h>
void hanoi(int n, char src, char dst, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", src, dst);
        return;
    }
    hanoi(n - 1, src, aux, dst);
    printf("Move disk %d from %c to %c\n", n, src, dst);
    hanoi(n - 1, aux, dst, src);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        hanoi(n, 'A', 'C', 'B');
        printf("%lld\n", (1LL << n) - 1);
    }
    return 0;
}