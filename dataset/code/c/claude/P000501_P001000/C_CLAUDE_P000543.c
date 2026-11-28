/* P000543: Data Stream as Disjoint Intervals */
#include<stdio.h>
int lo[10001],hi[10001],n=0;
void add(int v){
    int nl=v,nh=v,j=0;
    for(int i=0;i<n;i++){
        if(hi[i]+1<nl||lo[i]>nh+1){lo[j]=lo[i];hi[j]=hi[i];j++;}
        else{if(lo[i]<nl)nl=lo[i];if(hi[i]>nh)nh=hi[i];}
    }
    lo[j]=nl;hi[j]=nh;n=j+1;
    // sort by lo
    for(int i=n-1;i>0&&lo[i]<lo[i-1];i--){int t=lo[i];lo[i]=lo[i-1];lo[i-1]=t;t=hi[i];hi[i]=hi[i-1];hi[i-1]=t;}
}
int main(){int q;scanf("%d",&q);
for(int i=0;i<q;i++){char cmd[20];scanf("%s",cmd);
    if(cmd[0]=='a'){int v;scanf("%d",&v);add(v);}
    else{for(int j=0;j<n;j++)printf("[%d,%d]%c",lo[j],hi[j],j<n-1?' ':'\n');}
}}
