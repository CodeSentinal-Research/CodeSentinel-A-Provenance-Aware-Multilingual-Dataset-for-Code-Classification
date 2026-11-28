#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(){
    int n; scanf("%d",&n);
    int a[2*n];
    for(int i=0;i<2*n;i++) scanf("%d",&a[i]);
    qsort(a,2*n,sizeof(int),cmp);
    printf("%.1f\n",(a[n-1]+a[n])/2.0);
}
