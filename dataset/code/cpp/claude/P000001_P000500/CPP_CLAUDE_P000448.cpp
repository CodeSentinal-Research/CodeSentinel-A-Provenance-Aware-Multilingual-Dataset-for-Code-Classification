#include<iostream>
using namespace std;
int main(){long long n;cin>>n;long long lo=0,hi=n;while(lo<hi){long long m=(lo+hi+1)/2;if(m*m<=n)lo=m;else hi=m-1;}cout<<lo<<"\n";}
