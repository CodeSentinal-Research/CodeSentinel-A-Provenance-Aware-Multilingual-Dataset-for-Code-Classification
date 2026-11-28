#include <stdio.h>
#include <string.h>
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int f[n+1];memset(f,0,sizeof(f));for(int i=0;i<n;i++){if(f[a[i]]){printf("%d\n",a[i]);return 0;}f[a[i]]++;}printf("-1\n");return 0;}
