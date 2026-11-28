#include<stdio.h>
int main(){char note[10001],mag[10001];scanf("%s %[^\n]",note,mag);int fn[256]={},fm[256]={};for(int i=0;note[i];i++)fn[(unsigned char)note[i]]++;for(int i=0;mag[i];i++)fm[(unsigned char)mag[i]]++;for(int i=0;i<256;i++)if(fn[i]>fm[i]){printf("No\n");return 0;}printf("Yes\n");}
