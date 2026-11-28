#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; scanf("%s", s);
    int count[256]={0};
    for(int i=0; s[i]; i++) count[s[i]]++;
    for(int i=0; i<256; i++) if(count[i]>0) printf("%c: %d\n", i, count[i]);
    return 0;
}
