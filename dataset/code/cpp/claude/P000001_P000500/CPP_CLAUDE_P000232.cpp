#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int r,c;cin>>r>>c;vector<int>a(r*c);for(auto&x:a)cin>>x;sort(a.begin(),a.end());cout<<a[(r*c)/2]<<"\n";}
