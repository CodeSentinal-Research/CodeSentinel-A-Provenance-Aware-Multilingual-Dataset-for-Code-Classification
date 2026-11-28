#include<iostream>
#include<string>
#include<vector>
using namespace std;
string s;vector<string>res;
void bt(int i,vector<string>&parts){
    if(parts.size()==4){if(i==(int)s.size()){string r=parts[0];for(int k=1;k<4;k++)r+="."+parts[k];res.push_back(r);}return;}
    for(int l=1;l<=3&&i+l<=(int)s.size();l++){
        string seg=s.substr(i,l);
        if(seg[0]=='0'&&l>1)break;
        if(stoi(seg)>255)break;
        parts.push_back(seg);bt(i+l,parts);parts.pop_back();
    }
}
int main(){cin>>s;vector<string>p;bt(0,p);for(auto&r:res)cout<<r<<"\n";}
