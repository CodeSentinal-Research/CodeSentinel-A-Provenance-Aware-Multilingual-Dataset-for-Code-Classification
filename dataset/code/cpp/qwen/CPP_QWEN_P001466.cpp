#include<bits/stdc++.h>
using namespace std;
int main(){string s;getline(cin,s);int l=0,r=s.size()-1;while(l<r){while(l<r&&!isalnum(s[l]))l++;while(l<r&&!isalnum(s[r]))r--;if(tolower(s[l])!=tolower(s[r])){cout<<"false"<<endl;return 0;}l++;r--;}cout<<"true"<<endl;return 0;}
