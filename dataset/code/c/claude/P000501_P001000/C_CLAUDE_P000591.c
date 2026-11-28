#include<stdio.h>
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);
int m;scanf("%d",&m);int found=-1;
for(int j=0;j<m;j++){int v;scanf("%d",&v);if(found<0)for(int i=0;i<n;i++)if(a[i]==v){found=v;break;}}
if(found>=0)printf("%d\n",found);else printf("null\n");}
