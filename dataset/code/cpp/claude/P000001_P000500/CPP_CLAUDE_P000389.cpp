#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
int main(){
    int n; cin>>n; cin.ignore();
    vector<string> recs(n);
    for(auto&r:recs) getline(cin,r);
    string dept; getline(cin,dept);
    bool found=false;
    for(auto&r:recs){
        istringstream iss(r); string f1,f2;
        if((iss>>f1>>f2) && f2==dept){cout<<r<<"\n";found=true;}
    }
    if(!found) cout<<"No Records Found\n";
}
