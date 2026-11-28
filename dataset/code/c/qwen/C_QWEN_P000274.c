#include <stdio.h>
#include <string.h>
int main() {
    char h[1001], n[1001]; scanf("%s %s", h, n);
    char *p = strstr(h, n);
    printf("%d\n", p ? (int)(p - h) : -1);
    return 0;
}
