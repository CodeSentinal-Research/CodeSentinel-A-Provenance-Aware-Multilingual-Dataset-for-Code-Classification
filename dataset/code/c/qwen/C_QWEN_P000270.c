#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; fgets(s, 1001, stdin);
    int len = strlen(s);
    if(s[len-1]=='\n') s[len-1]='\0';
    int cap=1;
    for(int i=0; s[i]; i++) {
        if(s[i]==' ') cap=1;
        else { if(cap && s[i]>='a' && s[i]<='z') s[i]-=32; cap=0; }
    }
    printf("%s\n", s);
    return 0;
}
