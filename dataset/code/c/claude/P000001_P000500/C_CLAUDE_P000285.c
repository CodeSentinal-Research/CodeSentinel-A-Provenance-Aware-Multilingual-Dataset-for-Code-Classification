#include<stdio.h>
int main(){char s1[1001],s2[1001];scanf("%s %s",s1,s2);int i=0;for(int j=0;s2[j];j++)if(s1[i]&&s2[j]==s1[i])i++;printf("%s\n",!s1[i]?"Yes":"No");}
