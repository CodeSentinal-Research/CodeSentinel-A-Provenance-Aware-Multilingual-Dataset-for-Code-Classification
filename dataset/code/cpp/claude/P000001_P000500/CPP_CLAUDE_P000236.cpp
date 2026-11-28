#include<iostream>
#include<vector>
using namespace std;
int main(){int n;cin>>n;vector<vector<int>>A(n,vector<int>(n)),sm(n,vector<int>(n));for(auto&r:A)for(auto&x:r)cin>>x;sm[n-1][n-1]=A[n-1][n-1];for(int j=n-2;j>=0;j--)sm[n-1][j]=max(A[n-1][j],sm[n-1][j+1]);for(int i=n-2;i>=0;i--)sm[i][n-1]=max(A[i][n-1],sm[i+1][n-1]);for(int i=n-2;i>=0;i--)for(int j=n-2;j>=0;j--)sm[i][j]=max({A[i][j],sm[i+1][j],sm[i][j+1]});int ans=INT_MIN;for(int i=0;i<n-1;i++)for(int j=0;j<n-1;j++)ans=max(ans,sm[i+1][j+1]-A[i][j]);cout<<ans<<"\n";}
