#include<iostream>
using namespace std;
int main(){int r,c;cin>>r>>c;int br=-1,bc=-1;for(int i=0;i<r;i++){int cnt=0;for(int j=0;j<c;j++){int x;cin>>x;cnt+=x;}if(cnt>bc){bc=cnt;br=i;}}cout<<br<<"\n";}
