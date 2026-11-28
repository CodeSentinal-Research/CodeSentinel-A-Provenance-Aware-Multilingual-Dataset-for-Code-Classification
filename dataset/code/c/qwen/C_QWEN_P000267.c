#include <stdio.h>
#include <string.h>
int main() {
    char s[1001], old_c, new_c; scanf("%s %c %c", s, &old_c, &new_c);
    for(int i=0; s[i]; i++) if(s[i]==old_c) s[i]=new_c;
    printf("%s\n", s);
    return 0;
}
