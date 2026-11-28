#include<stdio.h>
int main(){int n;scanf("%d",&n);long long a[n],tot=0,l=0;for(int i=0;i<n;i++){scanf("%lld",&a[i]);tot+=a[i];}
for(int i=0;i<n;i++){if(l==tot-l-a[i]){printf("%d\n",i);return 0;}l+=a[i];}printf("-1\n");}
