#include<stdio.h>
#include<string.h>
int main(){int n;scanf("%d",&n);char s[100001]="1",t[100001];for(int i=1;i<n;i++){int k=0,j=0,len=strlen(s);while(j<len){int cnt=1;while(j+cnt<len&&s[j+cnt]==s[j])cnt++;t[k++]=(char)('0'+cnt);t[k++]=s[j];j+=cnt;}t[k]=0;strcpy(s,t);}printf("%s\n",s);}
