#include <stdio.h>
#include <string.h>
int main() {
    char s[1001], res[1001]; scanf("%s", s);
    int seen[256]={0}, j=0;
    for(int i=0; s[i]; i++) if(!seen[s[i]]) { res[j++]=s[i]; seen[s[i]]=1; }
    res[j]='\0';
    printf("%s\n", res);
    return 0;
}
