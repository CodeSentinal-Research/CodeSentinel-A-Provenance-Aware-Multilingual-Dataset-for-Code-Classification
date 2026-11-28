#include <stdio.h>
#include <stdlib.h>
int main() {
    char s[201]; fgets(s, 201, stdin);
    printf("%d\n", atoi(s));
    return 0;
}
