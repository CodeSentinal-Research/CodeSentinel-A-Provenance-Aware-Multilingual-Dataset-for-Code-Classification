#include <stdio.h>
#include <string.h>
int main() {
    char s[200001]; scanf("%s", s);
    int count[256] = {0}, last[256];
    for(int i=0; i<256; i++) last[i] = -1;
    for(int i=0; s[i]; i++) { count[s[i]]++; last[s[i]] = i; }
    char stack[200001]; int top = -1;
    int in_stack[256] = {0};
    for(int i=0; s[i]; i++) {
        count[s[i]]--;
        if(in_stack[s[i]]) continue;
        while(top >= 0 && stack[top] > s[i] && last[stack[top]] > i) { in_stack[stack[top--]] = 0; }
        stack[++top] = s[i];
        in_stack[s[i]] = 1;
    }
    stack[top+1] = '\0';
    printf("%s\n", stack);
    return 0;
}
