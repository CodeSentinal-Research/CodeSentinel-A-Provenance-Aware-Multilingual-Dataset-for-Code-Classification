#include<iostream>
using namespace std;
int main(){int n;cin>>n;int M[n][n];for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>M[i][j];int c=0;for(int i=1;i<n;i++)if(M[c][i])c=i;for(int i=0;i<n;i++)if(i!=c&&(M[c][i]||!M[i][c])){cout<<-1<<"\n";return 0;}cout<<c<<"\n";}
