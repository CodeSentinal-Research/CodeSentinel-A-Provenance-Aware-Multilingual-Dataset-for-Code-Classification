#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> a(n+1,0);
    for(int i=0;i<n;i++){int x;cin>>x;a[x]=1;}
    bool first=true;
    for(int i=1;i<=n;i++) if(!a[i]){if(!first)cout<<' ';cout<<i;first=false;}
    cout<<"\n";
}
