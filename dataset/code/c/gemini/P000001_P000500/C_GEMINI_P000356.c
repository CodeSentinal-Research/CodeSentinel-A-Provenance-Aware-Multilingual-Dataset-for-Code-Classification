#include <stdio.h>
#include <string.h>

int main() {
    char s[100005], c;
    if (scanf("%100000s %c", s, &c) == 2) {
        char* p = strchr(s, c);
        if (p) printf("%ld\n", p - s);
        else printf("-1\n");
    }
    return 0;
}