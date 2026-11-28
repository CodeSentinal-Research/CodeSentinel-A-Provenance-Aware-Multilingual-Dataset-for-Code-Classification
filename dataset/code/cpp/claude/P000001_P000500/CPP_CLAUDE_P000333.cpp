#include<iostream>
#include<string>
using namespace std;
bool isSub(string&w,string&s){int i=0;for(char c:s)if(i<(int)w.size()&&c==w[i])i++;return i==(int)w.size();}
int main(){string s;cin>>s;int n;cin>>n;int cnt=0;while(n--){string w;cin>>w;if(isSub(w,s))cnt++;}cout<<cnt<<"\n";}
