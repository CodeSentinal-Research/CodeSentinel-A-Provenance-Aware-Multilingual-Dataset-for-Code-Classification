#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<tuple<string,string,float>>prod;for(int i=0;i<n;i++){string code,name;float price;cin>>code>>name>>price;prod.push_back({code,name,price});}string tcode;cin>>tcode;for(auto&[code,name,price]:prod)if(code==tcode){cout<<code<<" "<<name<<" "<<price<<endl;return 0;}cout<<"Product Not Found"<<endl;return 0;}
