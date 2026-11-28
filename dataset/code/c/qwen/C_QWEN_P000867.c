#include <stdio.h>
int main() {
    int x, y; scanf("%d%d", &x, &y);
    int res = x ^ y, count = 0;
    while(res) { count += res & 1; res >>= 1; }
    printf("%d\n", count);
    return 0;
}
