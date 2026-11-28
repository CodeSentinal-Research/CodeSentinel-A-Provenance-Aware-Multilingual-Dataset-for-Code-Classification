#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(){
    int m,n; scanf("%d %d",&m,&n);
    int a[m+n];
    for(int i=0;i<m+n;i++) scanf("%d",&a[i]);
    int total=m+n;
    qsort(a,total,sizeof(int),cmp);
    if(total%2==1) printf("%d\n",a[total/2]);
    else printf("%.1f\n",(a[total/2-1]+a[total/2])/2.0);
}
