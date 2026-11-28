#include<iostream>
using namespace std;
int main(){int r,c;cin>>r>>c;int A[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)cin>>A[i][j];bool f=true;for(int i=0;i<r;i++){if(i%2==0)for(int j=0;j<c;j++){if(!f)cout<<" ";cout<<A[i][j];f=false;}else for(int j=c-1;j>=0;j--){if(!f)cout<<" ";cout<<A[i][j];f=false;}}cout<<"\n";}
