#include<bits/stdc++.h>
using namespace std;
int main(){int r,c;cin>>r>>c;vector<vector<long long>>dp(r,vector<long long>(c,0));dp[0][0]=1;for(int i=0;i<r;i++)for(int j=0;j<c;j++){if(i>0)dp[i][j]+=dp[i-1][j];if(j>0)dp[i][j]+=dp[i][j-1];}cout<<dp[r-1][c-1]<<endl;return 0;}
