#include<iostream>
#include<vector>
using namespace std;
int main(){int r1,c1,c2;cin>>r1>>c1>>c2;vector<vector<long long>>A(r1,vector<long long>(c1)),B(c1,vector<long long>(c2)),C(r1,vector<long long>(c2,0));for(auto&r:A)for(auto&x:r)cin>>x;for(auto&r:B)for(auto&x:r)cin>>x;for(int i=0;i<r1;i++)for(int j=0;j<c2;j++)for(int k=0;k<c1;k++)C[i][j]+=A[i][k]*B[k][j];for(int i=0;i<r1;i++){for(int j=0;j<c2;j++)cout<<C[i][j]<<" \n"[j==c2-1];}}
