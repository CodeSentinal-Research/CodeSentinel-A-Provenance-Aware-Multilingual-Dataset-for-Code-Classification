#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmpc(const void*a,const void*b){return *(char*)a-*(char*)b;}
int main(){int n;scanf("%d",&n);char w[n][101],key[n][101];for(int i=0;i<n;i++){scanf("%s",w[i]);strcpy(key[i],w[i]);qsort(key[i],strlen(key[i]),1,cmpc);}for(int i=0;i<n;i++){int first=1;for(int j=0;j<n;j++){if(strcmp(key[i],key[j])==0&&j>=i){if(!first)printf(" ");printf("%s",w[j]);first=0;}}if(!first)printf("\n");}}
/* Note: simplified output; grouping via sorted keys */
