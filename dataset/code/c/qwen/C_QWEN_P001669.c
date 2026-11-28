#include <stdio.h>
#include <string.h>

int main() {
    char s[100005]; scanf("%s", s);
    int stack = 1;
    for(int i=0; s[i]; i++) {
        if(s[i] == ',') continue;
        if(s[i] == '#') stack--;
        else stack++;
        if(stack == 0 && s[i+1]) { printf("false\n"); return 0; }
    }
    printf("%s\n", stack == 0 ? "true" : "false");
    return 0;
}
