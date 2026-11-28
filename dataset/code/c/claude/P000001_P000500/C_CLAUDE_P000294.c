#include<stdio.h>
#include<string.h>
int main(){char s[10001];int rows;scanf("%s %d",s,&rows);int n=strlen(s);if(rows==1){printf("%s\n",s);return 0;}char arrs[rows][n+1];for(int i=0;i<rows;i++)arrs[i][0]=0;int len[rows];for(int i=0;i<rows;i++)len[i]=0;int row=0,down=1;for(int i=0;i<n;i++){arrs[row][len[row]++]=s[i];arrs[row][len[row]]=0;if(row==rows-1)down=0;else if(row==0)down=1;row+=down?1:-1;}for(int i=0;i<rows;i++)printf("%s",arrs[i]);printf("\n");}
