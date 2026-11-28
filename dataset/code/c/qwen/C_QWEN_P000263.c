#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; scanf("%s", s);
    int count[256]={0}, len=strlen(s);
    for(int i=0; s[i]; i++) count[s[i]]++;
    char res = '-';
    for(int i=len-1; i>=0; i--) if(count[s[i]]==1) { res=s[i]; break; }
    printf("%c\n", res);
    return 0;
}
