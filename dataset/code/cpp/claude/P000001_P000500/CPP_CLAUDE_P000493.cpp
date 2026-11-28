#include<iostream>
#include<string>
using namespace std;
int main(){string s;int k;cin>>s>>k;string stk="";for(char c:s){while(k>0&&!stk.empty()&&stk.back()>c){stk.pop_back();k--;}stk+=c;}stk=stk.substr(0,stk.size()-k);int start=stk.find_first_not_of('0');cout<<(start==string::npos?"0":stk.substr(start))<<"\n";}
