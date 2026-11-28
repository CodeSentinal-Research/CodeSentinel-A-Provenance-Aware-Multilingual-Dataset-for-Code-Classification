#include<bits/stdc++.h>
using namespace std;
int main(){string s;cin>>s;unordered_map<char,int>m;int last=-1;for(int i=0;i<s.size();i++){m[s[i]]=i;last=max(last,m[s[i]]);if(i==last){cout<<last+1<<" ";last=i+1;}}cout<<endl;return 0;}
