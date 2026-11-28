#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; scanf("%s", s);
    for(int i=0; s[i]; i++) if(s[i]>='a' && s[i]<='z') s[i] -= 32;
    printf("%s\n", s);
    return 0;
}
