#include<stdio.h>
char buf[100];int first=1;
void gen(int n,int o,int c,int k){
if(o==n&&c==n){if(!first)printf(" ");printf("%s",buf);first=0;return;}
if(o<n){buf[k]="(";gen(n,o+1,c,k+1);}
if(c<o){buf[k]=")";gen(n,o,c+1,k+1);}}
int main(){int n;scanf("%d",&n);buf[n*2]=0;gen(n,0,0,0);printf("\n");}
