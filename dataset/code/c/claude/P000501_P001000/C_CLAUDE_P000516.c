#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(){int n;scanf("%d",&n);int a[n],s[n];for(int i=0;i<n;i++){scanf("%d",&a[i]);s[i]=a[i];}
qsort(s,n,sizeof(int),cmp);int l=0,r=n-1;
while(l<n&&a[l]==s[l])l++;while(r>=0&&a[r]==s[r])r--;
printf("%d\n",l>r?0:r-l+1);}
