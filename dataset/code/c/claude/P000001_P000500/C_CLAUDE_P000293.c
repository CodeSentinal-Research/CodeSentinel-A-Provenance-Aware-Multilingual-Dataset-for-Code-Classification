#include<stdio.h>
#include<string.h>
int main(){int n;scanf("%d\n",&n);char strs[100][10001];for(int i=0;i<n;i++)fgets(strs[i],10001,stdin);char enc[1000001]="";for(int i=0;i<n;i++){char tmp[20];sprintf(tmp,"%d#",(int)strlen(strs[i])-1);strcat(enc,tmp);strncat(enc,strs[i],strlen(strs[i])-1);}printf("%s\n",enc);/* decode */int i=0,len=strlen(enc);while(i<len){int l=0;while(enc[i]!="#")l=l*10+(enc[i++]-"0");i++;char w[10001];strncpy(w,enc+i,l);w[l]=0;printf("%s ",w);i+=l;}printf("\n");}
