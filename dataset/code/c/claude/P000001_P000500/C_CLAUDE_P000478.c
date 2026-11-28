#include<stdio.h>
#include<stdlib.h>
int n,c,stalls[100001];
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int ok(int d){int cnt=1,last=stalls[0];for(int i=1;i<n;i++)if(stalls[i]-last>=d){cnt++;last=stalls[i];}return cnt>=c;}
int main(){scanf("%d %d",&n,&c);for(int i=0;i<n;i++)scanf("%d",&stalls[i]);qsort(stalls,n,sizeof(int),cmp);int lo=1,hi=stalls[n-1]-stalls[0],ans=0;while(lo<=hi){int mid=(lo+hi)/2;if(ok(mid)){ans=mid;lo=mid+1;}else hi=mid-1;}printf("%d\n",ans);}
