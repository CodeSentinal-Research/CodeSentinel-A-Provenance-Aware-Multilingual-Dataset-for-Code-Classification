#include <stdio.h>
int main(){
    int n; scanf("%d",&n);
    int a[n],freq[1001]={0};
    for(int i=0;i<n;i++){scanf("%d",&a[i]);freq[a[i]]++;}
    int mx=0,res=a[0];
    for(int i=0;i<n;i++) if(freq[a[i]]>mx){mx=freq[a[i]];res=a[i];}
    printf("%d\n",res);
}
