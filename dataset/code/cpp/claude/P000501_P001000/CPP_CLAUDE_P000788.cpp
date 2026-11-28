#include<iostream>
#include<vector>
using namespace std;
int main(){int n;cin>>n;vector<double>a(n);for(auto&v:a)cin>>v;int k;cin>>k;
double s=0;for(int i=0;i<k;i++)s+=a[i];double best=s;
for(int i=k;i<n;i++){s+=a[i]-a[i-k];best=max(best,s);}
cout<<best/k<<"\n";}
