#include<iostream>
#include<unordered_map>
using namespace std;
int main(){string s;cin>>s;unordered_map<char,int>f;for(char c:s)f[c]++;for(char c:s)if(f[c]==1){cout<<c<<"\n";return 0;}cout<<-1<<"\n";}
