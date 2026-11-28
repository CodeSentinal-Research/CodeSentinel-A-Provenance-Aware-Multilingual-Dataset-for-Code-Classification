#include <iostream>
#include <vector>
using namespace std;
void hf(vector<int>&a,int i,int n){int sm=i;while(1){int l=2*i+1,r=2*i+2;if(l<n&&a[l]<a[sm])sm=l;if(r<n&&a[r]<a[sm])sm=r;if(sm==i)break;swap(a[i],a[sm]);i=sm;}}
int main(){int n,m;cin>>n>>m;vector<int>a(n),b(m);for(int i=0;i<n;i++)cin>>a[i];for(int i=0;i<m;i++)cin>>b[i];for(int x:b)a.push_back(x);for(int i=a.size()/2-1;i>=0;i--)hf(a,i,a.size());for(int x:a)cout<<x<<" ";cout<<endl;return 0;}
