#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int total = 1 << n;
    for (int i = 0; i < total; i++) {
        printf("%d\n", i ^ (i >> 1));
    }
    return 0;
}
