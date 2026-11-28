#include<stdio.h>
int n,m,a[1001];
int ok(long long cap){int p=1;long long c=0;for(int i=0;i<n;i++){if(c+a[i]>cap){p++;c=a[i];}else c+=a[i];}return p<=m;}
int main(){scanf("%d %d",&n,&m);long long lo=0,hi=0;for(int i=0;i<n;i++){scanf("%d",&a[i]);if(a[i]>lo)lo=a[i];hi+=a[i];}while(lo<hi){long long mid=(lo+hi)/2;if(ok(mid))hi=mid;else lo=mid+1;}printf("%lld\n",lo);}
