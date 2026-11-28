#include <iostream>
#include <vector>
using namespace std;
void hfU(vector<int>&a,int i){while(i>0&&a[i]>a[(i-1)/2]){swap(a[i],a[(i-1)/2]);i=(i-1)/2;}}
void hfD(vector<int>&a,int i,int n){int lg=i;while(1){int l=2*i+1,r=2*i+2;if(l<n&&a[l]>a[lg])lg=l;if(r<n&&a[r]>a[lg])lg=r;if(lg==i)break;swap(a[i],a[lg]);i=lg;}}
int main(){int n,q;cin>>n>>q;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];while(q--){int idx,nv;cin>>idx>>nv;a[idx]=nv;hfU(a,idx);hfD(a,idx,n);}for(int x:a)cout<<x<<" ";cout<<endl;return 0;}
