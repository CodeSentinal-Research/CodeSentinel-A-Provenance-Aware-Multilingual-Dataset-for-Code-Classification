#include<stdio.h>
int n,m,a[1001];
int ok(long long mid){int s=1;long long c=0;for(int i=0;i<n;i++){if(a[i]>mid)return 0;if(c+a[i]>mid){s++;c=a[i];}else c+=a[i];}return s<=m;}
int main(){scanf("%d %d",&n,&m);for(int i=0;i<n;i++)scanf("%d",&a[i]);long long lo=0,hi=0;for(int i=0;i<n;i++){if(a[i]>lo)lo=a[i];hi+=a[i];}long long ans=hi;while(lo<=hi){long long mid=(lo+hi)/2;if(ok(mid)){ans=mid;hi=mid-1;}else lo=mid+1;}printf("%lld\n",ans);}
