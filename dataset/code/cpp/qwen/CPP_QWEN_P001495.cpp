#include<bits/stdc++.h>
using namespace std;
int main(){string s,t;cin>>s>>t;int i=0,j=0;while(i<s.size()&&j<t.size()){if(s[i]==t[j])j++;i++;}cout<<t.size()-j<<endl;return 0;}
