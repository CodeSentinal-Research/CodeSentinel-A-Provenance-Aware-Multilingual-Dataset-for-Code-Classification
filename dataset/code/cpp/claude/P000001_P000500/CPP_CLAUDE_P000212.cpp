#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(auto&x:a) cin>>x;
    for(int i=0;i<n;i++)
        if(a[i]==0&&(i==0||a[i-1]==0)&&(i==n-1||a[i+1]==0)){a[i]=1;k--;}
    cout<<(k<=0?"true":"false")<<"\n";
}
