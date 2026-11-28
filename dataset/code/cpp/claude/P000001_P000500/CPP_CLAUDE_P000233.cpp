#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int maxHist(vector<int>&h){stack<int>st;int mx=0;h.push_back(0);for(int i=0;i<(int)h.size();i++){while(!st.empty()&&h[st.top()]>=h[i]){int ht=h[st.top()];st.pop();int w=st.empty()?i:i-st.top()-1;mx=max(mx,ht*w);}st.push(i);}h.pop_back();return mx;}
int main(){int r,c;cin>>r>>c;vector<int>h(c,0);int ans=0;for(int i=0;i<r;i++){for(int j=0;j<c;j++){int x;cin>>x;h[j]=x?h[j]+1:0;}ans=max(ans,maxHist(h));}cout<<ans<<"\n";}
