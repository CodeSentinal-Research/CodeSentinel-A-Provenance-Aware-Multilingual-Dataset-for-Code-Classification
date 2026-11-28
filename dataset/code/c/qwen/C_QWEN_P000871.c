#include <stdio.h>
int main() {
    int left, right; scanf("%d%d", &left, &right);
    while(left < right) { left >>= 1; right >>= 1; }
    printf("%d\n", left);
    return 0;
}
