#include<stdio.h>
int main(){int n;scanf("%d",&n);char res[10]="";int ri=0;while(n){n--;res[ri++]='A'+n%26;n/=26;}for(int i=ri-1;i>=0;i--)printf("%c",res[i]);printf("\n");}
