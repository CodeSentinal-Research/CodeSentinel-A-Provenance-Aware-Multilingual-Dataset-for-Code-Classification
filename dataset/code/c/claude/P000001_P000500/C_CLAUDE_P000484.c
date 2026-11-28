#include<stdio.h>
#include<string.h>
int main(){
    char s[10001];scanf("%s",s);
    char stk_str[100][1001];int stk_num[100],top=0;
    char cur[10001]="";int num=0;
    for(int i=0;s[i];i++){
        if(s[i]>='0'&&s[i]<='9')num=num*10+(s[i]-'0');
        else if(s[i]=='['){strcpy(stk_str[top],cur);stk_num[top]=num;top++;cur[0]=0;num=0;}
        else if(s[i]==']'){char tmp[10001];strcpy(tmp,stk_str[--top]);int k=stk_num[top];for(int j=0;j<k;j++)strcat(tmp,cur);strcpy(cur,tmp);}
        else{int l=strlen(cur);cur[l]=s[i];cur[l+1]=0;}
    }
    printf("%s\n",cur);
}
