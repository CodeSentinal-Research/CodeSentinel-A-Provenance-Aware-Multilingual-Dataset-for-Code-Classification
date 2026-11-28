#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char s[1001]; scanf("%s", s);
    int stack_i[1001], stack_n[1001], top=-1, i=0;
    char res[100001] = "";
    while(s[i]) {
        if(s[i]>='0' && s[i]<='9') { int n=0; while(s[i]>='0' && s[i]<='9') { n=n*10+(s[i]-'0'); i++; } stack_n[++top]=n; }
        else if(s[i]=='[') { stack_i[++top]=strlen(res); i++; }
        else if(s[i]==']') {
            int n=stack_n[top], start=stack_i[top]; top--;
            char sub[1001]; strncpy(sub, res+start, strlen(res)-start); sub[strlen(res)-start]='\0';
            res[start]='\0';
            for(int k=0; k<n; k++) strcat(res, sub);
            i++;
        } else { res[strlen(res)]=s[i]; res[strlen(res)+1]='\0'; i++; }
    }
    printf("%s\n", res);
    return 0;
}
