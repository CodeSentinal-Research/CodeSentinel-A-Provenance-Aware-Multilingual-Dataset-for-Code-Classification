#include <stdio.h>
#include <string.h>
int main() {
    char s[65]; scanf("%s", s);
    long long res = 0;
    for(int i=0; s[i]; i++) res = res * 2 + (s[i] - '0');
    printf("%lld\n", res);
    return 0;
}
