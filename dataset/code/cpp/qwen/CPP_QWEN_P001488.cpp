#include<bits/stdc++.h>
using namespace std;
int main(){string s;cin>>s;int l=0,r=s.size()-1;while(l<r&&s[l]==s[r]){l++;r--;}cout<<r-l+1<<endl;return 0;}
