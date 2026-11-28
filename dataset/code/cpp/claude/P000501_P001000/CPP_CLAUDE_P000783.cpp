#include<iostream>
#include<vector>
using namespace std;
int main(){int n;cin>>n;vector<int>pre(n+1,0);int v;
for(int i=0;i<n;i++){cin>>v;pre[i+1]=pre[i]+(v%2==0?1:0);}
int q;cin>>q;while(q--){int l,r;cin>>l>>r;cout<<pre[r+1]-pre[l]<<"\n";}
}
