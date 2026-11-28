#include<iostream>
#include<vector>
using namespace std;
int main(){int r,c;cin>>r>>c;vector<vector<int>>A(r,vector<int>(c));for(auto&row:A)for(auto&x:row)cin>>x;vector<bool>R(r),C(c);for(int i=0;i<r;i++)for(int j=0;j<c;j++)if(A[i][j]){R[i]=C[j]=true;}for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<(R[i]||C[j]?1:A[i][j])<<" \n"[j==c-1];}}
