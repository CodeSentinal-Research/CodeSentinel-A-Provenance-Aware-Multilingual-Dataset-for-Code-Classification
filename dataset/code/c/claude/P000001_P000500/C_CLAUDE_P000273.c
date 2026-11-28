#include<stdio.h>
int main(){char s[10001];scanf("%s",s);char st[10001];int top=0,ok=1;for(int i=0;s[i]&&ok;i++){if(s[i]=="("||s[i]=="["||s[i]=="{")st[top++]=s[i];else{if(!top)ok=0;else{char o=st[--top];if((s[i]==")"&&o!="(")||(s[i]=="]"&&o!="[")||(s[i]=="}"&&o!="{"))ok=0;}}}if(top)ok=0;printf("%s\n",ok?"Valid":"Invalid");}
