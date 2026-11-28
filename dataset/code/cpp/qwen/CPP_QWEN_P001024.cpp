#include <iostream>
#include <vector>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];int i;cin>>i;int l=2*i+1,r=2*i+2;cout<<(l<n?a[l]:-1)<<" "<<(r<n?a[r]:-1)<<endl;return 0;}
