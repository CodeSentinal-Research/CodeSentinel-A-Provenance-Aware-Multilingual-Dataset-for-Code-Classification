#include <stdio.h>
#include <string.h>
int main() {
    char s1[1001], s2[1001]; scanf("%s %s", s1, s2);
    if(strlen(s1) != strlen(s2)) { printf("No\n"); return 0; }
    int c1[256]={0}, c2[256]={0};
    for(int i=0; s1[i]; i++) { c1[s1[i]]++; c2[s2[i]]++; }
    int ana=1;
    for(int i=0; i<256; i++) if(c1[i]!=c2[i]) { ana=0; break; }
    printf("%s\n", ana ? "Yes" : "No");
    return 0;
}
