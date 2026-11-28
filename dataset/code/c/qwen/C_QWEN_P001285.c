#include <stdio.h>
int main() {
    int x, y; scanf("%d%d", &x, &y);
    int ops = 0;
    while(y > x) {
        if(y % 2 == 0) y /= 2;
        else y++;
        ops++;
    }
    ops += x - y;
    printf("%d\n", ops);
    return 0;
}
