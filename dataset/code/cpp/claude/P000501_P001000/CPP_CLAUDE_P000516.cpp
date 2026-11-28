#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(auto&v:a)cin>>v;vector<int>s(a);sort(s.begin(),s.end());
int l=0,r=n-1;while(l<n&&a[l]==s[l])l++;while(r>=0&&a[r]==s[r])r--;
cout<<(l>r?0:r-l+1)<<"\n";}
