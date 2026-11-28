#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; fgets(s, 1001, stdin);
    int words=0, in_word=0;
    for(int i=0; s[i]; i++) {
        if(s[i]!=' ' && s[i]!='\n') { if(!in_word) { words++; in_word=1; } }
        else in_word=0;
    }
    printf("%d\n", words);
    return 0;
}
