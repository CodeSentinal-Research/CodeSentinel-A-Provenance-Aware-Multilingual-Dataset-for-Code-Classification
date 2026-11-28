#include<stdio.h>
int main(){int n;scanf("%d",&n);int a[n],x;for(int i=0;i<n;i++)scanf("%d",&a[i]);scanf("%d",&x);for(int i=0;i<n;i++)if(a[i]==x){printf("Present\n");return 0;}printf("Missing\n");}
