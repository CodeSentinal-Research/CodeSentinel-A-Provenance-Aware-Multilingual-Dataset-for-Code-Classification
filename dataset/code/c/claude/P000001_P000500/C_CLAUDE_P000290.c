#include<stdio.h>
#include<string.h>
int main(){char t[10001],p[10001];scanf("%s %s",t,p);int n=strlen(t),m=strlen(p),need[256]={},win[256]={};for(int i=0;p[i];i++)need[(unsigned char)p[i]]++;int matched=0;for(int i=0;i<m;i++){win[(unsigned char)t[i]]++;if(win[(unsigned char)t[i]]<=need[(unsigned char)t[i]])matched++;}if(matched==m)printf("0 ");for(int i=m;i<n;i++){int in=(unsigned char)t[i],out=(unsigned char)t[i-m];win[in]++;if(win[in]<=need[in])matched++;win[out]--;if(win[out]<need[out])matched--;if(matched==m)printf("%d ",i-m+1);}printf("\n");}
