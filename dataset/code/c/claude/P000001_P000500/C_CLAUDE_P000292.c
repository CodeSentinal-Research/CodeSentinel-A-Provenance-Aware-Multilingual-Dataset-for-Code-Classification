/* Decode String - stack based */
#include<stdio.h>
#include<string.h>
int main(){char s[10001];scanf("%s",s);char out[100001]="";char stk[100001][10001];int cnt[10001],top=0;int n=strlen(s);char cur[10001]="";int curcnt=0;
for(int i=0;i<n;i++){
if(s[i]>="0"&&s[i]<="9"){curcnt=curcnt*10+(s[i]-"0");}
else if(s[i]=="["){strcpy(stk[top],cur);cnt[top]=curcnt;top++;cur[0]=0;curcnt=0;}
else if(s[i]=="]"){char tmp[100001]="";for(int k=0;k<cnt[top-1];k++)strcat(tmp,cur);top--;strcpy(cur,stk[top]);strcat(cur,tmp);}
else{int l=strlen(cur);cur[l]=s[i];cur[l+1]=0;}}
printf("%s\n",cur);}
