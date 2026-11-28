#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
int main(){
    int n; cin>>n; cin.ignore();
    vector<string> prods(n);
    for(auto&r:prods) getline(cin,r);
    string brand; getline(cin,brand);
    bool found=false;
    for(auto&r:prods){
        istringstream iss(r); string nm,br;
        if((iss>>nm>>br) && br==brand){cout<<r<<"\n";found=true;}
    }
    if(!found) cout<<"No Records Found\n";
}
