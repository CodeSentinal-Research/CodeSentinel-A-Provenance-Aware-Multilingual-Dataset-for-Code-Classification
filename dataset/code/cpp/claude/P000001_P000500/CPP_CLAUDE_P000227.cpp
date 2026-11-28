#include<iostream>
#include<vector>
#include<climits>
using namespace std;
long long kadane(vector<long long>&a){long long b=LLONG_MIN,c=0,mn=0;for(auto x:a){c+=x;b=max(b,c-mn);mn=min(mn,c);}return b;}
int main(){int r,c;cin>>r>>c;vector<vector<long long>>A(r,vector<long long>(c));for(auto&row:A)for(auto&x:row)cin>>x;long long best=LLONG_MIN;for(int l=0;l<c;l++){vector<long long>row(r,0);for(int ri=l;ri<c;ri++){for(int i=0;i<r;i++)row[i]+=A[i][ri];best=max(best,kadane(row);}}cout<<best<<"\n";}
