#include <stdio.h>
#include <string.h>
int main() {
    char order[27], s[1001]; scanf("%s %s", order, s);
    int count[256] = {0};
    for(int i=0; s[i]; i++) count[s[i]]++;
    for(int i=0; order[i]; i++) {
        while(count[order[i]] > 0) { printf("%c", order[i]); count[order[i]]--; }
    }
    for(int i=0; i<256; i++) {
        while(count[i] > 0) { printf("%c", i); count[i]--; }
    }
    printf("\n");
    return 0;
}
