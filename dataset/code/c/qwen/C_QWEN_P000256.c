#include <stdio.h>
#include <string.h>
int main() {
    char s[1001], res[1001]; scanf("%s", s);
    int j=0;
    for(int i=0; s[i]; i++) { char c=s[i]; if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') res[j++]=c; }
    res[j]='\0';
    printf("%s\n", res);
    return 0;
}
