#include <stdio.h>
int main(){
    int n; scanf("%d",&n);
    int a[n+1];
    for(int i=0;i<=n;i++) a[i]=0;
    for(int i=0;i<n;i++){int x;scanf("%d",&x);a[x]=1;}
    int first=1;
    for(int i=1;i<=n;i++) if(!a[i]){if(!first)printf(" ");printf("%d",i);first=0;}
    printf("\n");
}
