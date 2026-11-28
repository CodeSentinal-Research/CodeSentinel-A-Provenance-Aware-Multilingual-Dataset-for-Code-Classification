#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){string s;getline(cin,s);int wn;cin>>wn;cin.ignore();int n=s.size();vector<bool>bold(n,false);
for(int k=0;k<wn;k++){string w;getline(cin,w);int wl=w.size();size_t pos=s.find(w);while(pos!=string::npos){for(size_t i=pos;i<pos+wl;i++)bold[i]=true;pos=s.find(w,pos+1);}}
string res="";for(int i=0;i<n;i++){if(bold[i]&&(i==0||!bold[i-1]))res+="<b>";res+=s[i];if(bold[i]&&(i==n-1||!bold[i+1]))res+="</b>";}cout<<res<<"\n";}
