#include<iostream>
#include<string>
using namespace std;
int main(){string h,n;cin>>h>>n;size_t p=h.find(n);cout<<(p==string::npos?-1:(int)p)<<"\n";}
