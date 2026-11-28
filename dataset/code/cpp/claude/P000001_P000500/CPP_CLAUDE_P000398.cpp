#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
int main(){
    int n; cin>>n; cin.ignore();
    vector<string> vehicles(n);
    for(auto&r:vehicles) getline(cin,r);
    string mfr; getline(cin,mfr);
    bool found=false;
    for(auto&r:vehicles){
        istringstream iss(r); string reg,make;
        if((iss>>reg>>make) && make==mfr){cout<<r<<"\n";found=true;}
    }
    if(!found) cout<<"No Records Found\n";
}
