#include <stdio.h>
int main(){
    int n; scanf("%d",&n);
    int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int freq[50001]={0},first[50001],last[50001];
    for(int i=0;i<=50000;i++) first[i]=last[i]=-1;
    int deg=0;
    for(int i=0;i<n;i++){
        freq[a[i]]++;
        if(first[a[i]]==-1) first[a[i]]=i;
        last[a[i]]=i;
        if(freq[a[i]]>deg) deg=freq[a[i]];
    }
    int res=n;
    for(int i=0;i<n;i++){
        if(freq[a[i]]==deg){
            int len=last[a[i]]-first[a[i]]+1;
            if(len<res) res=len;
        }
    }
    printf("%d\n",res);
}
