#include <iostream>
#include <set>
#include <string>
using namespace std;
int main(){int q;cin>>q;set<int>s;int cur=1;while(q--){string op;cin>>op;if(op=="popSmallest"){if(!s.empty()){int v=*s.begin();s.erase(s.begin());cout<<v<<" ";}else{cout<<cur<<" ";cur++;}}else{int x;cin>>x;s.insert(x);}}cout<<endl;return 0;}
