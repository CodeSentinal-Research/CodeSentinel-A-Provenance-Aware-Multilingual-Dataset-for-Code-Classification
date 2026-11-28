#include <stdio.h>
int main(){int n,t;scanf("%d %d",&n,&t);long long a[n];for(int i=0;i<n;i++)scanf("%lld",&a[i]);int lo=0,hi=n-1;while(lo<hi){long long s=a[lo]+a[hi];if(s==t){printf("%d %d\n",lo,hi);return 0;}else if(s<t)lo++;else hi--;}printf("-1 -1\n");return 0;}
