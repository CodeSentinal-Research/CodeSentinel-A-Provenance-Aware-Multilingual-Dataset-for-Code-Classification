#include<stdio.h>
char*keys[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
char buf[1000][20];int cnt=0;
void bt(char*digits,int di,char*cur,int ci){
if(!digits[di]){char tmp[ci+1];tmp[ci]=0;for(int i=0;i<ci;i++)tmp[i]=cur[i];strcpy(buf[cnt++],tmp);return;}
char*k=keys[digits[di]-"0"];for(int i=0;k[i];i++){cur[ci]=k[i];bt(digits,di+1,cur,ci+1);}}
int main(){char s[20];scanf("%s",s);char cur[20];bt(s,0,cur,0);for(int i=0;i<cnt;i++)printf("%s%c",buf[i],i<cnt-1?" ":"\n");}
