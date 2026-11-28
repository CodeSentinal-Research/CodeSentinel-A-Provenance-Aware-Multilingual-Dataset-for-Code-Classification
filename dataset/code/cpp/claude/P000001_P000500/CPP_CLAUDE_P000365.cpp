#include<iostream>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;int a[n];for(auto&v:a)cin>>v;cout<<min_element(a,a+n)-a<<"\n";}
