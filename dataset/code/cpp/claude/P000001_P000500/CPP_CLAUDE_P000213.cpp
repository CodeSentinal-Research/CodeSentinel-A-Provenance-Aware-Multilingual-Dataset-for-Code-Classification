#include <iostream>
#include <set>
using namespace std;
int main(){
    int n; cin>>n;
    set<long long> s;
    for(int i=0;i<n;i++){long long x;cin>>x;s.insert(x);if(s.size()>3)s.erase(s.begin());}
    if(s.size()==3) cout<<*s.begin()<<"\n";
    else cout<<*s.rbegin()<<"\n";
}
