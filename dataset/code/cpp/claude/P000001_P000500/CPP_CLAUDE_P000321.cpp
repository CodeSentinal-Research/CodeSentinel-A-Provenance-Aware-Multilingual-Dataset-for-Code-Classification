#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;cin.ignore();string rows[]={"qwertyuiop","asdfghjkl","zxcvbnm"};while(n--){string w;getline(cin,w);for(auto&r:rows){bool ok=true;for(char c:w)if(r.find(tolower(c))==string::npos){ok=false;break;}if(ok){cout<<w<<"\n";break;}}}};
