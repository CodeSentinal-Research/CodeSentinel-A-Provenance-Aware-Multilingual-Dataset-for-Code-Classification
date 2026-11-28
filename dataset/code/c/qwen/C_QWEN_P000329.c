#include <stdio.h>
#include <string.h>
int main() {
    char s[1001], t[1001]; scanf("%s %s", s, t);
    int res = 0;
    for(int i=0; s[i]; i++) res ^= s[i];
    for(int i=0; t[i]; i++) res ^= t[i];
    printf("%c\n", res);
    return 0;
}
