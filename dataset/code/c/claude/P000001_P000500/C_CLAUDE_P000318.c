#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){char word[101],abbr[101];scanf("%s %s",word,abbr);int i=0,j=0,n=strlen(word),m=strlen(abbr);while(i<n&&j<m){if(isdigit(abbr[j])){if(abbr[j]=='0'){printf("No\n");return 0;}int num=0;while(j<m&&isdigit(abbr[j]))num=num*10+(abbr[j++]-'0');i+=num;}else{if(word[i]!=abbr[j]){printf("No\n");return 0;}i++;j++;}}printf("%s\n",(i==n&&j==m)?"Yes":"No");}
