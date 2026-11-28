#include<stdio.h>
#include<limits.h>
long long kadane(long long*a,int n){long long best=LLONG_MIN,cur=0,mn=0;for(int i=0;i<n;i++){cur+=a[i];if(cur-mn>best)best=cur-mn;if(cur<mn)mn=cur;}return best;}
int main(){int r,c;scanf("%d %d",&r,&c);long long A[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)scanf("%lld",&A[i][j]);long long best=LLONG_MIN;for(int l=0;l<c;l++){long long row[r];for(int i=0;i<r;i++)row[i]=0;for(int ri=l;ri<c;ri++){for(int i=0;i<r;i++)row[i]+=A[i][ri];long long k=kadane(row,r);if(k>best)best=k;}}printf("%lld\n",best);}
