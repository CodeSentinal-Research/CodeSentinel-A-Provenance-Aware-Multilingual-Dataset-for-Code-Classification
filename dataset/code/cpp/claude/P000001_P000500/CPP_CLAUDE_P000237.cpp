#include<iostream>
#include<vector>
using namespace std;
int main(){int r,c,k;cin>>r>>c>>k;k%=c;for(int i=0;i<r;i++){vector<int>row(c);for(auto&x:row)cin>>x;for(int j=0;j<c;j++)cout<<row[(j+k)%c]<<" \n"[j==c-1];}}
