#include <stdio.h>
#include <string.h>
void rev(char *s, int l, int r) { while(l<r) { char t=s[l]; s[l]=s[r]; s[r]=t; l++; r--; } }
int main() {
    char s[1001]; fgets(s, 1001, stdin);
    int len = strlen(s);
    if(s[len-1]=='\n') s[len-1]='\0';
    rev(s, 0, strlen(s)-1);
    int start=0;
    for(int i=0; s[i]; i++) {
        if(s[i]==' ') { rev(s, start, i-1); start=i+1; }
    }
    rev(s, start, strlen(s)-1);
    printf("%s\n", s);
    return 0;
}
