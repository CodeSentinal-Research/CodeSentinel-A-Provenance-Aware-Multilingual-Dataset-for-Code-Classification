#include <stdio.h>
#include <stdlib.h>
int main() {
    char b[100];
    if (scanf("%99s", b) == 1) {
        long val = strtol(b, NULL, 2);
        printf("%ld\n", val);
    }
    return 0;
}