#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
    int n,k; cin>>n>>k;
    vector<double> a(n);
    for(auto&x:a) cin>>x;
    double win=0;
    for(int i=0;i<k;i++) win+=a[i];
    double best=win;
    for(int i=k;i<n;i++){win+=a[i]-a[i-k];best=max(best,win);}
    cout<<fixed<<setprecision(5)<<best/k<<"\n";
}
