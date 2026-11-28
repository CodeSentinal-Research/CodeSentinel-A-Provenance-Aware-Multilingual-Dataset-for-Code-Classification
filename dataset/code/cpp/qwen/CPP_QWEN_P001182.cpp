#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];int jumps=0,cur=0,nxt=0;for(int i=0;i<n-1;i++){nxt=max(nxt,i+a[i]);if(i==cur){jumps++;cur=nxt;}}cout<<jumps<<endl;return 0;}
