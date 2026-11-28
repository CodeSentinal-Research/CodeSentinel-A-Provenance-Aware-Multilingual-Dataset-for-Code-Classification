#include<iostream>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;int A[n][n];for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>A[i][j];for(int i=0;i<n;i++){int mn=*min_element(A[i],A[i]+n);int jm=min_element(A[i],A[i]+n)-A[i];bool ok=true;for(int k=0;k<n;k++)if(A[k][jm]<mn)ok=false;if(ok){cout<<i<<" "<<jm<<" "<<mn<<"\n";return 0;}}cout<<"No Saddle Point\n";}
