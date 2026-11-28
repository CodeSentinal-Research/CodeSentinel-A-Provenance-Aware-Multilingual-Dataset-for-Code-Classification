#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){string a,b;cin>>a>>b;int m=a.size(),n=b.size();
vector<int>pos(m+n,0);
for(int i=m-1;i>=0;i--)for(int j=n-1;j>=0;j--){
    int mul=(a[i]-'0')*(b[j]-'0'),p1=i+j,p2=i+j+1,tot=mul+pos[p2];
    pos[p2]=tot%10;pos[p1]+=tot/10;
}
string res="";bool lead=true;for(int x:pos){if(lead&&!x)continue;lead=false;res+=('0'+x);}
cout<<(res.empty()?"0":res)<<"\n";}
