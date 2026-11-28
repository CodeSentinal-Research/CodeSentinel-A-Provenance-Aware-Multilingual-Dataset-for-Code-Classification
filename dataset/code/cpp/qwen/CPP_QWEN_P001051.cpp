#include <iostream>
#include <vector>
using namespace std;
int main(){int n,q;cin>>n>>q;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];while(q--){int idx,nv;cin>>idx>>nv;a[idx]=nv;}bool ok=true;for(int i=0;i<n;i++){int l=2*i+1,r=2*i+2;if(l<n&&a[i]>a[l])ok=false;if(r<n&&a[i]>a[r])ok=false;}cout<<(ok?"VALID":"INVALID")<<endl;return 0;}
