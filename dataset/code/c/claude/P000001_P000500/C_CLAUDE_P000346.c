#include<stdio.h>
#include<string.h>
int isSub(char*w,char*s){int i=0;for(int j=0;s[j]&&w[i];j++)if(s[j]==w[i])i++;return !w[i];}
int main(){char s[1001];scanf("%s",s);int n;scanf("%d",&n);char best[101]="";for(int k=0;k<n;k++){char w[101];scanf("%s",w);if(isSub(w,s)){int wl=strlen(w),bl=strlen(best);if(wl>bl||(wl==bl&&strcmp(w,best)<0))strcpy(best,w);}}printf("%s\n",best);}
