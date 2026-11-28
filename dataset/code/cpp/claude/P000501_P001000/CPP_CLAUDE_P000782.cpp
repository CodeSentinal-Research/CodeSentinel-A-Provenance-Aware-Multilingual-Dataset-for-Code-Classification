#include<iostream>
#include<vector>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(auto&v:a)cin>>v;
int q;cin>>q;while(q--){int l,r,cnt=0;cin>>l>>r;for(int v:a)if(v>=l&&v<=r)cnt++;cout<<cnt<<"\n";}
}
