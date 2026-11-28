#include <stdio.h>
int main(){
    int n; scanf("%d",&n);
    long long a[n],total=0;
    for(int i=0;i<n;i++){scanf("%lld",&a[i]);total+=a[i];}
    long long left=0;
    for(int i=0;i<n;i++){
        if(left==(total-left-a[i])){printf("%d\n",i);return 0;}
        left+=a[i];
    }
    printf("-1\n");
}
