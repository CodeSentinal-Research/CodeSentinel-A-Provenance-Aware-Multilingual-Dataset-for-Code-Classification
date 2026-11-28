#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; int k; scanf("%s %d", s, &k);
    char stack[1001]; int count[1001] = {0}; int top = -1;
    for(int i=0; s[i]; i++) {
        if(top >= 0 && stack[top] == s[i]) count[top]++;
        else { stack[++top] = s[i]; count[top] = 1; }
        if(count[top] == k) top -= k;
    }
    stack[top+1] = '\0';
    printf("%s\n", stack);
    return 0;
}
