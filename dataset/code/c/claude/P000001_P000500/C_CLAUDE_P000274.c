#include<stdio.h>
#include<string.h>
int main(){char h[10001],n[10001];scanf("%s %s",h,n);char*p=strstr(h,n);if(p)printf("%d\n",(int)(p-h));else printf("-1\n");}
