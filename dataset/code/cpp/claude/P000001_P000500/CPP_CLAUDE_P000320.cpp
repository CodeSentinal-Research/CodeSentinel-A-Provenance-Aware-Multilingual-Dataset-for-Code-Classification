#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;
int main(){string s,c;cin>>s>>c;int n=s.size();vector<int>res(n,n);int prev=-n;for(int i=0;i<n;i++){if(s[i]==c[0])prev=i;res[i]=i-prev;}prev=2*n;for(int i=n-1;i>=0;i--){if(s[i]==c[0])prev=i;res[i]=min(res[i],prev-i);}for(int i=0;i<n;i++)cout<<res[i]<<" \n"[i==n-1];}
