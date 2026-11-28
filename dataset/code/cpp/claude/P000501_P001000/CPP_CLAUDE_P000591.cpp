#include<iostream>
#include<unordered_set>
using namespace std;
int main(){int n;cin>>n;unordered_set<int>sa;for(int i=0;i<n;i++){int v;cin>>v;sa.insert(v);}
int m;cin>>m;for(int i=0;i<m;i++){int v;cin>>v;if(sa.count(v)){cout<<v<<"\n";return 0;}}cout<<"null\n";}
