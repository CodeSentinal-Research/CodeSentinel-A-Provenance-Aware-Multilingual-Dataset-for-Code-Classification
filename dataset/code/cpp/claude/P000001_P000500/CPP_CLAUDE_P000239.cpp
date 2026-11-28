#include<iostream>
using namespace std;
int main(){int r,c;cin>>r>>c;int A[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)cin>>A[i][j];bool f=true;auto pr=[&](int v){if(!f)cout<<" ";cout<<v;f=false;};for(int j=0;j<c;j++)pr(A[0][j]);for(int i=1;i<r-1;i++){pr(A[i][0]);pr(A[i][c-1]);}if(r>1)for(int j=0;j<c;j++)pr(A[r-1][j]);cout<<"\n";}
