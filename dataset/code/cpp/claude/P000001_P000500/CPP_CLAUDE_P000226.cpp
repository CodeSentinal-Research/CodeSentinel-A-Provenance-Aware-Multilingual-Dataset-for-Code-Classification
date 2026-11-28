#include<iostream>
#include<vector>
using namespace std;
long long mc(vector<int>&a,int l,int r){
if(r-l<=1)return 0;
int m=(l+r)/2;long long inv=mc(a,l,m)+mc(a,m,r);
vector<int>tmp;int i=l,j=m;
while(i<m&&j<r){if(a[i]<=a[j])tmp.push_back(a[i++]);else{tmp.push_back(a[j++]);inv+=m-i;}}
while(i<m)tmp.push_back(a[i++]);while(j<r)tmp.push_back(a[j++]);
for(int k=l;k<r;k++)a[k]=tmp[k-l];return inv;}
int main(){int n;cin>>n;vector<int>a(n);for(auto&x:a)cin>>x;cout<<mc(a,0,n)<<"\n";}
