#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; scanf("%s", s);
    char num_stack[1001]; int num_top=-1;
    char char_stack[1001]; int char_top=-1;
    char result[100001]; int res_idx=0;
    int i=0;
    while(s[i]) {
        if(s[i]>='0' && s[i]<='9') {
            int n=0;
            while(s[i]>='0' && s[i]<='9') { n=n*10+(s[i]-'0'); i++; }
            num_stack[++num_top]=n;
        } else if(s[i]=='[') {
            char_stack[++char_top]='[';
            i++;
        } else if(s[i]==']') {
            char temp[1001]; int t_idx=0;
            while(char_top>=0 && char_stack[char_top]!='[') temp[t_idx++]=char_stack[char_top--];
            char_top--;
            int n=num_stack[num_top--];
            for(int k=0; k<n; k++) for(int j=t_idx-1; j>=0; j--) char_stack[++char_top]=temp[j];
            i++;
        } else {
            char_stack[++char_top]=s[i++];
        }
    }
    char_stack[char_top+1]='\0';
    printf("%s\n", char_stack);
    return 0;
}
