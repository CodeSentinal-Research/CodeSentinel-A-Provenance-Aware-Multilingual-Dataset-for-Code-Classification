#include <stdio.h>
int main() {
    int x; scanf("%d", &x);
    if(x < 0) { printf("false\n"); return 0; }
    int orig = x, res = 0;
    while(x) { res = res * 10 + x % 10; x /= 10; }
    printf("%s\n", orig == res ? "true" : "false");
    return 0;
}
