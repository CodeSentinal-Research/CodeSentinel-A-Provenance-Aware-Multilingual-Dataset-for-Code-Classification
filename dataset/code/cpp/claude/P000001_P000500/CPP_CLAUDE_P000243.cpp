#include<iostream>
using namespace std;
int main(){int r,c,t;cin>>r>>c>>t;int A[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)cin>>A[i][j];int i=0,j=c-1;while(i<r&&j>=0){if(A[i][j]==t){cout<<"Found\n";return 0;}else if(A[i][j]>t)j--;else i++;}cout<<"Not Found\n";}
