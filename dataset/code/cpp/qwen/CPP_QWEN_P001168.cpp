#include<bits/stdc++.h>
using namespace std;
int main(){int n,k;cin>>n>>k;if(n==1){cout<<k<<endl;return 0;}long long same=k,diff=(long long)k*(k-1);for(int i=2;i<n;i++){long long ns=diff,nd=(same+diff)*(k-1);same=ns;diff=nd;}cout<<same+diff<<endl;return 0;}
