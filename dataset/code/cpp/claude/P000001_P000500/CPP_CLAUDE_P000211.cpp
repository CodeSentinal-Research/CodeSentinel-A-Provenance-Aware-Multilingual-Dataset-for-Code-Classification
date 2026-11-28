#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(auto&x:a) cin>>x;
    sort(a.begin(),a.end());
    long long opt1=(long long)a[n-1]*a[n-2]*a[n-3];
    long long opt2=(long long)a[0]*a[1]*a[n-1];
    cout<<max(opt1,opt2)<<"\n";
}
