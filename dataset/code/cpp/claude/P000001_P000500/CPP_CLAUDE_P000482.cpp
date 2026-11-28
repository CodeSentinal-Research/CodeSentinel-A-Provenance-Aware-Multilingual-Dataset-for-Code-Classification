#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;
int main(){int n;cin>>n;vector<int>nums1(n);for(auto&v:nums1)cin>>v;int m;cin>>m;vector<int>nums2(m);for(auto&v:nums2)cin>>v;stack<int>stk;unordered_map<int,int>mp;for(int v:nums2){while(!stk.empty()&&stk.top()<v){mp[stk.top()]=v;stk.pop();}stk.push(v);}for(int i=0;i<n;i++)cout<<(mp.count(nums1[i])?mp[nums1[i]]:-1)<<" \n"[i==n-1];}
