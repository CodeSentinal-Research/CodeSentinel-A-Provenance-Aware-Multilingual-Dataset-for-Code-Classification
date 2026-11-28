#include <stdio.h>
#include <string.h>
int main() {
    char s1[1001], s2[1001]; scanf("%s %s", s1, s2);
    int i=0, j=0;
    while(s1[i] && s2[j]) { if(s1[i]==s2[j]) j++; i++; }
    printf("%s\n", s2[j]=='\0' ? "Yes" : "No");
    return 0;
}
