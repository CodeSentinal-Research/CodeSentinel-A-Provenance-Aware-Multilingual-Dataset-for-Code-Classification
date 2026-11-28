#include<iostream>
using namespace std;
int main(){int n;cin>>n;int A[n][n];for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>A[i][j];for(int i=0;i<n;i++){for(int j=0;j<n;j++)cout<<(j>=i?A[i][j]:0)<<" \n"[j==n-1];}}
