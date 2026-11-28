#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int n; cin>>n; cin.ignore();
    vector<string> recs(n);
    for(auto&r:recs) getline(cin,r);
    string roll; getline(cin,roll);
    for(auto&r:recs){
        string key=r.substr(0, r.find(' '));
        if(key==roll){cout<<r<<"\n";return 0;}
    }
    cout<<"Record Not Found\n";
}
