#include <iostream>
#include <vector>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];int idx,nv;cin>>idx>>nv;a[idx]=nv;while(idx>0&&a[idx]<a[(idx-1)/2]){swap(a[idx],a[(idx-1)/2]);idx=(idx-1)/2;}for(int x:a)cout<<x<<" ";cout<<endl;return 0;}
