#include<iostream>
#include<vector>
using namespace std;
int main(){int n;cin>>n;vector<int>h(n);for(auto&v:h)cin>>v;vector<int>L(n),R(n);L[0]=h[0];for(int i=1;i<n;i++)L[i]=max(L[i-1],h[i]);R[n-1]=h[n-1];for(int i=n-2;i>=0;i--)R[i]=max(R[i+1],h[i]);long long w=0;for(int i=0;i<n;i++)w+=min(L[i],R[i])-h[i];cout<<w<<"\n";}
