#include<iostream>
#include<unordered_set>
using namespace std;
int main(){int n;cin>>n;unordered_set<int>s;for(int i=0;i<n;i++){int x;cin>>x;if(s.count(x)){cout<<x<<"\n";return 0;}s.insert(x);}cout<<-1<<"\n";}
