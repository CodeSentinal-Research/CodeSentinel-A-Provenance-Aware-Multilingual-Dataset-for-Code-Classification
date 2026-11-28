#include <stdio.h>
#include <string.h>
int main() {
    char s[200001]; scanf("%s", s);
    int open = 0, close = 0;
    for(int i=0; s[i]; i++) {
        if(s[i] == '(') open++;
        else if(open > 0) open--;
        else close++;
    }
    printf("%d\n", open + close);
    return 0;
}
