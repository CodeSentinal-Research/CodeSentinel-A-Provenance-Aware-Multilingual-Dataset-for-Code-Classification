#include <stdio.h>
#include <string.h>
int main() {
    char s[1001], res[2001]; scanf("%s", s);
    int j=0;
    for(int i=0; s[i]; ) {
        char c = s[i]; int count=0;
        while(s[i]==c) { count++; i++; }
        res[j++] = c;
        if(count > 1) { sprintf(res+j, "%d", count); j += strlen(res+j); }
    }
    res[j]='\0';
    printf("%s\n", strlen(res) < strlen(s) ? res : s);
    return 0;
}
