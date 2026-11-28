#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; fgets(s, 1001, stdin);
    int count = 0, in_seg = 0;
    for(int i=0; s[i]; i++) {
        if(s[i] != ' ' && s[i] != '\n') { if(!in_seg) { count++; in_seg=1; } }
        else in_seg = 0;
    }
    printf("%d\n", count);
    return 0;
}
