#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(){
    int n; scanf("%d",&n);
    int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    for(int i=0;i+1<n;i+=2){int t=a[i];a[i]=a[i+1];a[i+1]=t;}
    for(int i=0;i<n;i++) printf("%d%c",a[i],i<n-1?' ':'\n');
}
