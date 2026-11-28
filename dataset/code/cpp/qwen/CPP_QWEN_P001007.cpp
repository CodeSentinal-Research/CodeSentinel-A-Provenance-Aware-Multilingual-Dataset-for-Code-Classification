#include <iostream>
#include <vector>
using namespace std;
void hf(vector<int>&a,int i,int n){int lg=i;while(1){int l=2*i+1,r=2*i+2;if(l<n&&a[l]>a[lg])lg=l;if(r<n&&a[r]>a[lg])lg=r;if(lg==i)break;swap(a[i],a[lg]);i=lg;}}
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];int v;cin>>v;a[0]=v;hf(a,0,n);for(int x:a)cout<<x<<" ";cout<<endl;return 0;}
