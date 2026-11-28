#include<bits/stdc++.h>
using namespace std;
int main(){string s;getline(cin,s);int l=0,r=s.size()-1;auto isV=[](char c){c=tolower(c);return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';};while(l<r){while(l<r&&!isV(s[l]))l++;while(l<r&&!isV(s[r]))r--;swap(s[l],s[r]);l++;r--;}cout<<s<<endl;return 0;}
