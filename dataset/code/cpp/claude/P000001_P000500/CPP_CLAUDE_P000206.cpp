#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int m,n; cin>>m>>n;
    vector<int> merged(m+n);
    for(auto&x:merged) cin>>x;
    sort(merged.begin(),merged.end());
    int total=m+n;
    if(total%2==1) cout<<merged[total/2]<<"\n";
    else{double med=(merged[total/2-1]+merged[total/2])/2.0;cout<<(med==(int)med?(int)med:med)<<"\n";}
}
