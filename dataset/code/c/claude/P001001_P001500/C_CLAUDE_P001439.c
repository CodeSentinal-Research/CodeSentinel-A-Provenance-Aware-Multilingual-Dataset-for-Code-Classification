#include <stdio.h>
#include <string.h>
int main(){int n;scanf("%d",&n);int a[n],mx=0;for(int i=0;i<n;i++){scanf("%d",&a[i]);if(a[i]>mx)mx=a[i];}int f[mx+1];memset(f,0,sizeof(f));for(int i=0;i<n;i++)f[a[i]]++;for(int i=0;i<=mx;i++)if(f[i])printf("%d: %d\n",i,f[i]);return 0;}
