#include <stdio.h>
#include <string.h>
int main() {
    char s[10001]; scanf("%s", s);
    int stack=0;
    char *token = strtok(s, ",");
    while(token) {
        if(strcmp(token, "#")==0) stack--; else stack++;
        if(stack<0) { printf("false\n"); return 0; }
        token = strtok(NULL, ",");
    }
    printf("%s\n", stack==0 ? "true" : "false");
    return 0;
}
