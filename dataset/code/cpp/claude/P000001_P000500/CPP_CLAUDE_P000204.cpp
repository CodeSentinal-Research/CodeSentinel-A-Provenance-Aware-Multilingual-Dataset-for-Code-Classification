#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(auto&x:a) cin>>x;
    sort(a.begin(),a.end());
    for(int i=0;i+1<n;i+=2) swap(a[i],a[i+1]);
    for(int i=0;i<n;i++) cout<<a[i]<<" \n"[i==n-1];
}
