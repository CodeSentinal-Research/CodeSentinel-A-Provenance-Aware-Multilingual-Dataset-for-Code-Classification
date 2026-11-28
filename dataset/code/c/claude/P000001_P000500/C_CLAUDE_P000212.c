#include <stdio.h>
int main(){
    int n,k; scanf("%d %d",&n,&k);
    int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        if(a[i]==0 && (i==0||a[i-1]==0) && (i==n-1||a[i+1]==0)){
            a[i]=1; k--;
        }
    }
    printf("%s\n",k<=0?"true":"false");
}
