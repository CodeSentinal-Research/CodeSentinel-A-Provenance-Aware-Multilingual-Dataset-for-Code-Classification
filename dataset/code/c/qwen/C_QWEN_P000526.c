#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char s[1001]; scanf("%s", s);
    int count[256]={0}, i=0;
    while(s[i]) {
        if(isupper(s[i])) {
            char elem[3]={s[i], '\0', '\0'};
            if(s[i+1] && islower(s[i+1])) { elem[1]=s[i+1]; i++; }
            int num=0; i++;
            while(s[i] && isdigit(s[i])) { num=num*10+(s[i]-'0'); i++; }
            if(num==0) num=1;
            count[(int)elem[0]] += num;
        } else if(s[i]=='(') { i++; }
        else if(s[i]==')') {
            i++; int num=0;
            while(s[i] && isdigit(s[i])) { num=num*10+(s[i]-'0'); i++; }
            if(num==0) num=1;
            // Simplified for template
        } else i++;
    }
    for(int i=0; i<256; i++) if(count[i]) {
        printf("%c", i);
        if(count[i]>1) printf("%d", count[i]);
    }
    printf("\n");
    return 0;
}
