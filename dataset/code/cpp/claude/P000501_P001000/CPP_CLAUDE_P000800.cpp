#include<iostream>
#include<vector>
using namespace std;
int main(){int n,m;cin>>n>>m;
vector<vector<long long>>p(n+1,vector<long long>(m+1,0));
for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){int v;cin>>v;p[i][j]=v+p[i-1][j]+p[i][j-1]-p[i-1][j-1];}
int q;cin>>q;while(q--){int r1,c1,r2,c2;cin>>r1>>c1>>r2>>c2;
    cout<<p[r2+1][c2+1]-p[r1][c2+1]-p[r2+1][c1]+p[r1][c1]<<"\n";}
}
