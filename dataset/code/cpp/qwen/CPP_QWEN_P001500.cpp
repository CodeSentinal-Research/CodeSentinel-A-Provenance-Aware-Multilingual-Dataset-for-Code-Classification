#include<bits/stdc++.h>
using namespace std;
int main(){string s;cin>>s;int l=0,r=s.size()-1;while(l<r){if(s[l]==s[r]){l++;r--;}else{auto chk=[&](int i,int j){while(i<j){if(s[i]!=s[j])return false;i++;j--;}return true;};if(chk(l+1,r)||chk(l,r-1)){cout<<"true"<<endl;return 0;}cout<<"false"<<endl;return 0;}}cout<<"true"<<endl;return 0;}
