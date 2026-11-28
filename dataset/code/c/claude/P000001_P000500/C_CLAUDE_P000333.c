#include<stdio.h>
#include<string.h>
int isSub(char*w,char*s){int i=0;for(int j=0;s[j]&&w[i];j++)if(s[j]==w[i])i++;return !w[i];}
int main(){char s[10001];scanf("%s",s);int n;scanf("%d",&n);int cnt=0;for(int k=0;k<n;k++){char w[101];scanf("%s",w);if(isSub(w,s))cnt++;}printf("%d\n",cnt);}
