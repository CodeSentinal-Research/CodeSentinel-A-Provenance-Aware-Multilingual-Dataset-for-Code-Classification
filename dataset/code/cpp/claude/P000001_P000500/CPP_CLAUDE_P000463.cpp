#include<iostream>
#include<vector>
using namespace std;
int main(){int s1,s2,s3;cin>>s1>>s2>>s3;vector<int>a(s1),b(s2),c(s3);for(auto&v:a)cin>>v;for(auto&v:b)cin>>v;for(auto&v:c)cin>>v;int i=0,j=0,k=0;while(i<s1&&j<s2&&k<s3){if(a[i]==b[j]&&b[j]==c[k]){cout<<a[i]<<" ";i++;j++;k++;}else if(a[i]<=b[j]&&a[i]<=c[k])i++;else if(b[j]<=a[i]&&b[j]<=c[k])j++;else k++;}cout<<"\n";}
