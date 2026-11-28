#include <stdio.h>
#include <string.h>
int main() {
    char s[100001]; char c; scanf("%s %c", s, &c);
    for(int i=0; s[i]; i++) if(s[i]==c) { printf("%d\n", i); return 0; }
    printf("-1\n");
    return 0;
}
