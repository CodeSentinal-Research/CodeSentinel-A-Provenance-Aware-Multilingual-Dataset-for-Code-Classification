#include<stdio.h>
#define MAXP 100001
int pre[MAXP];int has[MAXP];
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int p;scanf("%d",&p);
long long tot=0;for(int i=0;i<n;i++)tot+=a[i];int r=(int)(tot%p);if(r==0){printf("0\n");return 0;}
for(int i=0;i<p;i++){pre[i]=-1;has[i]=0;}pre[0]=0;
int s=0,best=n;
for(int i=0;i<n;i++){s=(s+a[i])%p;int t=((s-r)%p+p)%p;if(has[t]){int len=i-pre[t]+1;if(len<n&&len<best)best=len;}if(!has[s]){pre[s]=i;has[s]=1;}}
printf("%d\n",best==n?-1:best);}
