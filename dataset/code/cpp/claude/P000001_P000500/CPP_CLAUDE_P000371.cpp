#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
    int n; cin>>n; cin.ignore();
    unordered_map<string,string> mp;
    for(int i=0;i<n;i++){
        string line; getline(cin,line);
        string key = line.substr(0, line.find(' '));
        mp[key] = line;
    }
    string q; getline(cin,q);
    auto it = mp.find(q);
    cout << (it!=mp.end() ? it->second : "Record Not Found") << "\n";
}
