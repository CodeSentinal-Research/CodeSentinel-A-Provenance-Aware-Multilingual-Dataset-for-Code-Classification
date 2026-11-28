#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> merged(2*n);
    for(auto&x:merged) cin>>x;
    sort(merged.begin(),merged.end());
    double med=(merged[n-1]+merged[n])/2.0;
    if(med==(int)med) cout<<(int)med<<"\n";
    else cout<<med<<"\n";
}
