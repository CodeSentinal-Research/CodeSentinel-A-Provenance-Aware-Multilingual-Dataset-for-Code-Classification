#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);unordered_map<int,int>mp;for(int i=0;i<n;i++){cin>>a[i];if(mp[a[i]]==1){cout<<a[i]<<endl;return 0;}mp[a[i]]++;}cout<<-1<<endl;return 0;}
