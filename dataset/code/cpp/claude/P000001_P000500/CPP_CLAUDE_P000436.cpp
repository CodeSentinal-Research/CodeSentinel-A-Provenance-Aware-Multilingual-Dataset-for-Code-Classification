#include<iostream>
using namespace std;
int main(){
    int n,x; cin>>n>>x;
    int a[n]; for(auto&v:a) cin>>v;
    int lo=0,hi=n;
    while(lo<hi){int m=(lo+hi)/2;if(a[m]<x)lo=m+1;else hi=m;}
    cout<<lo<<"\n";
}
