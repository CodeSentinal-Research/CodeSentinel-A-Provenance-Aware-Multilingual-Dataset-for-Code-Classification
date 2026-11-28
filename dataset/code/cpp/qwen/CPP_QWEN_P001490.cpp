#include<bits/stdc++.h>
using namespace std;
int main(){string s;cin>>s;int res=0;for(int i=0;i<s.size();){int j=i;while(j<s.size()&&s[j]==s[i])j++;int k=j;while(k<s.size()&&s[k]!=s[i])k++;res+=min(j-i,k-j);i=k;}cout<<res<<endl;return 0;}
