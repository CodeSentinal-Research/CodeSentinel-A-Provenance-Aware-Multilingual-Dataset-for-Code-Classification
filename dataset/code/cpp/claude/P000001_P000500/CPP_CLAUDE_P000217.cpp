#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cin>>n;
    vector<long long> a(n);
    long long total=0;
    for(auto&x:a){cin>>x;total+=x;}
    long long left=0;
    for(int i=0;i<n;i++){
        if(left==total-left-a[i]){cout<<i<<"\n";return 0;}
        left+=a[i];
    }
    cout<<-1<<"\n";
}
