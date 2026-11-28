#include <stdio.h>
#include <string.h>
int main() {
    char text[1001], broken[27]; scanf("%s %s", text, broken);
    int is_broken[256] = {0};
    for(int i=0; broken[i]; i++) is_broken[broken[i]] = 1;
    int count = 0, in_word = 1;
    for(int i=0; text[i]; i++) {
        if(text[i] == ' ') in_word = 1;
        else if(in_word) {
            if(!is_broken[text[i]]) count++;
            in_word = 0;
        }
    }
    printf("%d\n", count);
    return 0;
}
