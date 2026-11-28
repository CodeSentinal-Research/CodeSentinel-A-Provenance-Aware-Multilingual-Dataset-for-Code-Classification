#include <stdio.h>
int main() {
    int start, goal; scanf("%d%d", &start, &goal);
    int res = start ^ goal, count = 0;
    while(res) { count += res & 1; res >>= 1; }
    printf("%d\n", count);
    return 0;
}
