#include<bits/stdc++.h>
using namespace std;
int main(){string s;cin>>s;long long res=0,z=0;for(int i=s.size()-1;i>=0;i--){if(s[i]=='0')z++;else res+=z;}cout<<res<<endl;return 0;}
