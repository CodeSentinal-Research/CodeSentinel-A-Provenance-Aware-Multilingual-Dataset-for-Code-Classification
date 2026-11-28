#include<stdio.h>
#include<string.h>
int main(){char src[101],tgt[10001];scanf("%s %s",src,tgt);int sl=strlen(src),tl=strlen(tgt),j=0,cnt=0;while(j<tl){int prev=j;for(int i=0;i<sl&&j<tl;i++)if(src[i]==tgt[j])j++;if(j==prev){printf("-1\n");return 0;}cnt++;}printf("%d\n",cnt);}
