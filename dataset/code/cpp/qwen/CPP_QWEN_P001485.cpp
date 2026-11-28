#include<bits/stdc++.h>
using namespace std;
int main(){string n,t;cin>>n>>t;int i=0,j=0;while(i<t.size()){if(j<n.size()&&t[i]==n[j])j++;i++;}cout<<(j==n.size()?"true":"false")<<endl;return 0;}
