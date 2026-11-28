#include<iostream>
#include<cmath>
using namespace std;
int main(){int n;cin>>n;double A[n][n];for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>A[i][j];bool ok=true;for(int i=0;i<n&&ok;i++)for(int j=0;j<n&&ok;j++){double d=0;for(int k=0;k<n;k++)d+=A[i][k]*A[j][k];double e=(i==j)?1:0;if(fabs(d-e)>1e-6)ok=false;}cout<<(ok?"Yes":"No")<<"\n";}
