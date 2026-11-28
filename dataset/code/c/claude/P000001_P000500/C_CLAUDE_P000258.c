#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b){return *(char*)a-*(char*)b;}
int main(){char s[1001];scanf("%s",s);qsort(s,strlen(s),1,cmp);printf("%s\n",s);}
