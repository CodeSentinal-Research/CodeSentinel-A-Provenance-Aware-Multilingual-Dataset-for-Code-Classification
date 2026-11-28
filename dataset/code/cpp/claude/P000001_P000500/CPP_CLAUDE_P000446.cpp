#include<iostream>
#include<vector>
using namespace std;
int main(){int r,c,x;cin>>r>>c>>x;vector<vector<int>>mat(r,vector<int>(c));for(auto&row:mat)for(auto&v:row)cin>>v;int row=0,col=c-1;while(row<r&&col>=0){if(mat[row][col]==x){cout<<"Found\n";return 0;}else if(mat[row][col]>x)col--;else row++;}cout<<"Not Found\n";}
