#include <iostream>
#include <vector>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];int v;cin>>v;a.push_back(v);int i=n;while(i>0&&a[i]<a[(i-1)/2]){swap(a[i],a[(i-1)/2]);i=(i-1)/2;}for(int x:a)cout<<x<<" ";cout<<endl;return 0;}
