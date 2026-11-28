#include<iostream>
#include<vector>
using namespace std;
int main(){int r,c;cin>>r>>c;vector<vector<int>>A(r,vector<int>(c)),B(r,vector<int>(c));for(auto&row:A)for(auto&x:row)cin>>x;for(auto&row:B)for(auto&x:row)cin>>x;cout<<(A==B?"Identical":"Not Identical")<<"\n";}
