#include<stdio.h>
#include<string.h>
int main(){int n;scanf("%d\n",&n);char a[10001]="",tmp[1001];for(int i=0;i<n;i++){fgets(tmp,sizeof(tmp),stdin);tmp[strcspn(tmp,"\n")]=0;strcat(a,tmp);}int m;scanf("%d\n",&m);char b[10001]="";for(int i=0;i<m;i++){fgets(tmp,sizeof(tmp),stdin);tmp[strcspn(tmp,"\n")]=0;strcat(b,tmp);}printf("%s\n",strcmp(a,b)==0?"Yes":"No");}
