#include <stdio.h>
void to_binary(unsigned int n) {
    if (n > 1) to_binary(n / 2);
    printf("%d", n % 2);
}
int main() {
    unsigned int n;
    if (scanf("%u", &n) == 1) {
        to_binary(n);
        printf("\n");
    }
    return 0;
}