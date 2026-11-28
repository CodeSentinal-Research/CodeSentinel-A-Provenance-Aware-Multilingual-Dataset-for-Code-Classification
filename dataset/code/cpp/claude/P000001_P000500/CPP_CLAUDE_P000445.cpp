#include<iostream>
#include<vector>
using namespace std;
int main(){int r,c,x;cin>>r>>c>>x;vector<vector<int>>mat(r,vector<int>(c));for(auto&row:mat)for(auto&v:row)cin>>v;int lo=0,hi=r*c-1;while(lo<=hi){int m=(lo+hi)/2,v=mat[m/c][m%c];if(v==x){cout<<"Found\n";return 0;}else if(v<x)lo=m+1;else hi=m-1;}cout<<"Not Found\n";}
