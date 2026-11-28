#include<bits/stdc++.h>
using namespace std;
int main(){int r,c;cin>>r>>c;vector<vector<int>>g(r,vector<int>(c));for(int i=0;i<r;i++)for(int j=0;j<c;j++)cin>>g[i][j];vector<int>h(c,0);int mx=0;for(int i=0;i<r;i++){for(int j=0;j<c;j++)h[j]=(g[i][j]==1)?h[j]+1:0;stack<int>st;for(int j=0;j<=c;j++){int ht=(j==c)?0:h[j];while(!st.empty()&&h[st.top()]>ht){int hgt=h[st.top()];st.pop();int w=st.empty()?j:j-st.top()-1;mx=max(mx,hgt*w);}st.push(j);}}cout<<mx<<endl;return 0;}
