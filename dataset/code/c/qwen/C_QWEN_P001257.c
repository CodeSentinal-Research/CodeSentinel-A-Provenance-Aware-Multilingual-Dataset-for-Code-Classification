#include <stdio.h>
#include <string.h>
int main() {
    char s[200001]; scanf("%s", s);
    int last[256];
    for(int i=0; i<256; i++) last[i] = -1;
    for(int i=0; s[i]; i++) last[s[i]] = i;
    int start = 0;
    for(int i=0; s[i]; i++) {
        if(last[s[i]] > i) {
            // continue
        } else {
            printf("%d ", i - start + 1);
            start = i + 1;
        }
    }
    printf("\n");
    return 0;
}
