#include<iostream>
#include<vector>
using namespace std;
int main(){int r,c;cin>>r>>c;vector<vector<int>>mat(r,vector<int>(c));for(auto&row:mat)for(auto&v:row)cin>>v;for(int i=0;i<r;i++)for(int j=0;j<c;j++){int v=mat[i][j];if((i==0||v>mat[i-1][j])&&(i==r-1||v>mat[i+1][j])&&(j==0||v>mat[i][j-1])&&(j==c-1||v>mat[i][j+1])){cout<<v<<"\n";return 0;}}}
