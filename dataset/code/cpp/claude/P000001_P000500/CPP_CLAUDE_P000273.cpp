#include<iostream>
#include<stack>
using namespace std;
int main(){string s;cin>>s;stack<char>st;bool ok=true;for(char c:s){if(c=="("||c=="["||c=="{")st.push(c);else{if(st.empty())ok=false;else{char o=st.top();st.pop();if((c==")"&&o!="(")||(c=="]"&&o!="[")||(c=="}"&&o!="{"))ok=false;}}}if(!st.empty())ok=false;cout<<(ok?"Valid":"Invalid")<<"\n";}
