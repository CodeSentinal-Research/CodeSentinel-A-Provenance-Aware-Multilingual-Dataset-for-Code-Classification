#include<iostream>
#include<vector>
using namespace std;
int main(){int x;cin>>x;vector<int>a;int v;while(cin>>v)a.push_back(v);int n=a.size(),lo=0,hi=1;while(hi<n&&a[hi]<x){lo=hi;hi=min(hi*2,n-1);}while(lo<=hi){int m=(lo+hi)/2;if(a[m]==x){cout<<m<<"\n";return 0;}else if(a[m]<x)lo=m+1;else hi=m-1;}cout<<-1<<"\n";}
