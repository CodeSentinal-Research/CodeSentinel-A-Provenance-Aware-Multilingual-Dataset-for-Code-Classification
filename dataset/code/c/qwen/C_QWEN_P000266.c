#include <stdio.h>
#include <string.h>
int main() {
    char s[1001], c, res[1001]; scanf("%s %c", s, &c);
    int j=0;
    for(int i=0; s[i]; i++) if(s[i]!=c) res[j++]=s[i];
    res[j]='\0';
    printf("%s\n", res);
    return 0;
}
