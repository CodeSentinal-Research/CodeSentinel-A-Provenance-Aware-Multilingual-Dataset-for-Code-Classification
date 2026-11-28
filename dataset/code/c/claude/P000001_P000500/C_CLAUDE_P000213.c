#include <stdio.h>
#include <limits.h>
int main(){
    int n; scanf("%d",&n);
    long long first=LLONG_MIN,second=LLONG_MIN,third=LLONG_MIN;
    for(int i=0;i<n;i++){
        long long x; scanf("%lld",&x);
        if(x==first||x==second||x==third) continue;
        if(x>first){third=second;second=first;first=x;}
        else if(x>second){third=second;second=x;}
        else if(x>third) third=x;
    }
    printf("%lld\n",third!=LLONG_MIN?third:first);
}
