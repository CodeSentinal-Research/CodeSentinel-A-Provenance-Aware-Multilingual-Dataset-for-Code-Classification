#include<iostream>
#include<vector>
using namespace std;
int main(){int n;cin>>n;int prev=INT_MIN,v;for(int i=0;i<n;i++){cin>>v;if(v!=prev){cout<<v<<" ";prev=v;}}cout<<"\n";}
