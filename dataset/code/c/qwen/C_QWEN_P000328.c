#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; scanf("%s", s);
    int count[256] = {0};
    for(int i=0; s[i]; i++) count[s[i]]++;
    for(int i=0; s[i]; i++) {
        if(count[s[i]] == 1) { printf("%d\n", i); return 0; }
    }
    printf("-1\n");
    return 0;
}
