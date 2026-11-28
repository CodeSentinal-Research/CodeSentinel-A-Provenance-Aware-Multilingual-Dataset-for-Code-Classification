#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n),d(n);for(auto&x:a)cin>>x;for(auto&x:d)cin>>x;sort(a.begin(),a.end());sort(d.begin(),d.end());int p=1,res=1,i=1,j=0;while(i<n&&j<n){if(a[i]<=d[j]){p++;i++;}else{p--;j++;}res=max(res,p);}cout<<res<<"\n";}
