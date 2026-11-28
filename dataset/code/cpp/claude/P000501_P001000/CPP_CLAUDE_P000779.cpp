#include<iostream>
#include<vector>
using namespace std;
int main(){int n;cin>>n;vector<long long>pre(n+1,0);
for(int i=0;i<n;i++){int v;cin>>v;pre[i+1]=pre[i]+v;}
int q;cin>>q;while(q--){int l,r;cin>>l>>r;cout<<pre[r+1]-pre[l]<<"\n";}
}
