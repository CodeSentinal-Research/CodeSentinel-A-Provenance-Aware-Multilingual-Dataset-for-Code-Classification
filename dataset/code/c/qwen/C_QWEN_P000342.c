#include <stdio.h>
#include <string.h>
int main() {
    char s[101]; scanf("%s", s);
    for(int i=1; i<strlen(s); i+=2) {
        if(s[i]>='0' && s[i]<='9') s[i] = s[i-1] + (s[i]-'0');
    }
    printf("%s\n", s);
    return 0;
}
