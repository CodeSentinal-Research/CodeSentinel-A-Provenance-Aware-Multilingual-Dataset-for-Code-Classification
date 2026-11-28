#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
double det(vector<vector<double>>M){int n=M.size();double d=1;for(int i=0;i<n;i++){int p=i;for(int k=i+1;k<n;k++)if(fabs(M[k][i])>fabs(M[p][i]))p=k;if(p!=i){swap(M[i],M[p]);d*=-1;}if(M[i][i]==0)return 0;d*=M[i][i];for(int k=i+1;k<n;k++){double f=M[k][i]/M[i][i];for(int j=i;j<n;j++)M[k][j]-=f*M[i][j];}}return d;}
int main(){int n;cin>>n;vector<vector<double>>A(n,vector<double>(n));for(auto&r:A)for(auto&x:r)cin>>x;cout<<(int)round(det(A))<<"\n";}
