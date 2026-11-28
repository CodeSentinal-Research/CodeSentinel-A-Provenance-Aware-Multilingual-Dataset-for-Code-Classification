#include<iostream>
#include<vector>
using namespace std;
int main(){int r,c;cin>>r>>c;vector<vector<int>>A(r,vector<int>(c));for(auto&row:A)for(auto&x:row)cin>>x;for(int i=1;i<r;i++)for(int j=0;j<c;j++){int b=A[i-1][j];if(j>0)b=max(b,A[i-1][j-1]);if(j<c-1)b=max(b,A[i-1][j+1]);A[i][j]+=b;}cout<<*max_element(A[r-1].begin(),A[r-1].end())<<"\n";}
