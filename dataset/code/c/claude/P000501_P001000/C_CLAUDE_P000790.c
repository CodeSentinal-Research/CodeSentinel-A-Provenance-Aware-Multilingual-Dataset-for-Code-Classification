#include<stdio.h>
int mp[10001],has[10001];
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int k;scanf("%d",&k);
for(int i=0;i<10001;i++){mp[i]=-2;has[i]=0;}mp[0]=-1;has[0]=1;int s=0;
for(int i=0;i<n;i++){s=((s+a[i])%k+k)%k;if(has[s]&&i-mp[s]>=2){printf("true\n");return 0;}if(!has[s]){mp[s]=i;has[s]=1;}}
printf("false\n");}
