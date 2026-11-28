#include <stdio.h>
#include <string.h>
int main() {
    char s[100001]; char c; scanf("%s %c", s, &c);
    int count = 0;
    for(int i=0; s[i]; i++) if(s[i]==c) count++;
    printf("%d\n", count);
    return 0;
}
