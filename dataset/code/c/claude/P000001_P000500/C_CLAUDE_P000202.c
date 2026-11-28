#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(){
    int n; scanf("%d",&n);
    int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    int best=1,cur=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]+1) cur++;
        else if(a[i]!=a[i-1]) cur=1;
        if(cur>best) best=cur;
    }
    printf("%d\n",best);
}
