#include <stdio.h>
#include <string.h>
int main() {
    char w1[101], w2[101]; scanf("%s %s", w1, w2);
    int c1[256]={0}, c2[256]={0};
    for(int i=0; w1[i]; i++) c1[w1[i]]++;
    for(int i=0; w2[i]; i++) c2[w2[i]]++;
    for(int i=0; i<256; i++) if(abs(c1[i]-c2[i]) > 3) { printf("No\n"); return 0; }
    printf("Yes\n");
    return 0;
}
