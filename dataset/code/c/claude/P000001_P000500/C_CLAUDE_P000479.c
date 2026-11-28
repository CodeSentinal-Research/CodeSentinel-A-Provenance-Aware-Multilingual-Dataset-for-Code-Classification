#include <stdio.h>
#include <string.h>
int main(){char s[100001];scanf("%s",s);int st[100001],top=-1;for(int i=0;s[i];i++){char c=s[i];if(c=='('||c=='['||c=='{')st[++top]=c;else{if(top==-1){printf("No\n");return 0;}char t=st[top--];if((c==')' &&t!='(')||(c==']' &&t!='[')||(c=='}' &&t!= '{' )){printf("No\n");return 0;}}}printf("%s\n",top==-1?"Yes":"No");return 0;}
