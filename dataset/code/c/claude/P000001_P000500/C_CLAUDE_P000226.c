#include<stdio.h>
long long merge_count(int*a,int*tmp,int l,int r){
if(r-l<=1)return 0;
int m=(l+r)/2;
long long inv=merge_count(a,tmp,l,m)+merge_count(a,tmp,m,r);
int i=l,j=m,k=l;
while(i<m&&j<r){if(a[i]<=a[j])tmp[k++]=a[i++];else{tmp[k++]=a[j++];inv+=m-i;}}
while(i<m)tmp[k++]=a[i++];while(j<r)tmp[k++]=a[j++];
for(int x=l;x<r;x++)a[x]=tmp[x];return inv;}
int main(){int n;scanf("%d",&n);int a[n],tmp[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);printf("%lld\n",merge_count(a,tmp,0,n));}
