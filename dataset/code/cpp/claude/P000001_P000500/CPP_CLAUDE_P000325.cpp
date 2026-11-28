#include<iostream>
using namespace std;
int main(){string a,b;cin>>a>>b;cout<<(a==b?-1:(int)max(a.size(),b.size()))<<"\n";}
