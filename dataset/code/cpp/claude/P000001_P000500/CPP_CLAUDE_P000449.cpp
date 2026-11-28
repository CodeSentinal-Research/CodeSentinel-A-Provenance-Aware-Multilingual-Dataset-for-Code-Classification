#include<iostream>
#include<cmath>
using namespace std;
int main(){long long n;cin>>n;long long r=(long long)sqrt((double)n);while(r*r>n)r--;while((r+1)*(r+1)<=n)r++;cout<<(r*r==n?"Yes":"No")<<"\n";}
