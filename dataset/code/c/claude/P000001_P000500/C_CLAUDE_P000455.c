#include<stdio.h>
int n,d,w[50001];
int ok(long long cap){int days=1;long long c=0;for(int i=0;i<n;i++){if(c+w[i]>cap){days++;c=w[i];}else c+=w[i];}return days<=d;}
int main(){scanf("%d %d",&n,&d);for(int i=0;i<n;i++)scanf("%d",&w[i]);long long lo=0,hi=0;for(int i=0;i<n;i++){if(w[i]>lo)lo=w[i];hi+=w[i];}while(lo<hi){long long mid=(lo+hi)/2;if(ok(mid))hi=mid;else lo=mid+1;}printf("%lld\n",lo);}
