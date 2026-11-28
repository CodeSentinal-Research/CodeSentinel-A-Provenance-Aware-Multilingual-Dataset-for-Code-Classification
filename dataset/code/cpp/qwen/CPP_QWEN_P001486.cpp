#include<bits/stdc++.h>
using namespace std;
int main(){string v1,v2;cin>>v1>>v2;stringstream s1(v1),s2(v2);string p1,p2;while(getline(s1,p1,'.')||getline(s2,p2,'.')){int n1=p1.empty()?0:stoi(p1);int n2=p2.empty()?0:stoi(p2);if(n1<n2){cout<<-1<<endl;return 0;}if(n1>n2){cout<<1<<endl;return 0;}}cout<<0<<endl;return 0;}
