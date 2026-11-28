#include<stdio.h>
#include<stdlib.h>
int main(){char w1[101],w2[101];scanf("%s %s",w1,w2);int f[26]={0};for(int i=0;w1[i];i++)f[w1[i]-'a']++;for(int i=0;w2[i];i++)f[w2[i]-'a']--;for(int i=0;i<26;i++)if(abs(f[i])>3){printf("No\n");return 0;}printf("Yes\n");}
