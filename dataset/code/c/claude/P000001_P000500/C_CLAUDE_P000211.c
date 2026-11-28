#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(){
    int n; scanf("%d",&n);
    int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    long long opt1=(long long)a[n-1]*a[n-2]*a[n-3];
    long long opt2=(long long)a[0]*a[1]*a[n-1];
    printf("%lld\n",opt1>opt2?opt1:opt2);
}
