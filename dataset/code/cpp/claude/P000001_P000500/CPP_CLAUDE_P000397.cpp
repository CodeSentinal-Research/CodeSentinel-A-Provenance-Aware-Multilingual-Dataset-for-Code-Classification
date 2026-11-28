#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
int main(){
    int n; cin>>n; cin.ignore();
    vector<string> orders(n);
    for(auto&r:orders) getline(cin,r);
    string status; getline(cin,status);
    bool found=false;
    for(auto&r:orders){
        istringstream iss(r); string id,st;
        if((iss>>id>>st) && st==status){cout<<r<<"\n";found=true;}
    }
    if(!found) cout<<"No Orders Found\n";
}
