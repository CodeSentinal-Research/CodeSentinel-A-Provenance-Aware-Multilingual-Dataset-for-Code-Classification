#include <stdio.h>
#include <string.h>
int main() {
    char s[8]; scanf("%s", s);
    int res = 0;
    for(int i=0; s[i]; i++) res = res*26 + (s[i]-'A'+1);
    printf("%d\n", res);
    return 0;
}
