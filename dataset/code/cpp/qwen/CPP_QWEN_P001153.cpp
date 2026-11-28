#include<bits/stdc++.h>
using namespace std;
int main(){string s;cin>>s;int n=s.size();int cnt=0;for(int i=0;i<n;i++){for(int j=i;j<n;j++){bool ok=true;for(int k=i,l=j;k<l;k++,l--)if(s[k]!=s[l]){ok=false;break;}if(ok)cnt++;}}cout<<cnt<<endl;return 0;}
