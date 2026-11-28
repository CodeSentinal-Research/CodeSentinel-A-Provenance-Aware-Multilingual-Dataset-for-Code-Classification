#include<iostream>
using namespace std;
int main(){string src,tgt;cin>>src>>tgt;int sl=src.size(),tl=tgt.size(),j=0,cnt=0;while(j<tl){int prev=j;for(int i=0;i<sl&&j<tl;i++)if(src[i]==tgt[j])j++;if(j==prev){cout<<-1<<"\n";return 0;}cnt++;}cout<<cnt<<"\n";}
