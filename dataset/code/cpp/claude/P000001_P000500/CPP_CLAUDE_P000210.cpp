#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> a(n),b(n),c(n);
    for(auto&x:a) cin>>x;
    for(auto&x:b) cin>>x;
    for(auto&x:c) cin>>x;
    int i=0,j=0,k=0;bool first=true;
    while(i<n&&j<n&&k<n){
        if(a[i]==b[j]&&b[j]==c[k]){if(!first)cout<<' ';cout<<a[i];first=false;i++;j++;k++;}
        else if(a[i]<=b[j]&&a[i]<=c[k]) i++;
        else if(b[j]<=a[i]&&b[j]<=c[k]) j++;
        else k++;
    }
    cout<<"\n";
}
