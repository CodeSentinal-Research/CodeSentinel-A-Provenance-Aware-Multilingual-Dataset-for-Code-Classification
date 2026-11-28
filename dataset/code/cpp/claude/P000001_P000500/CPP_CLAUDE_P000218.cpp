#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> a(n); for(auto&x:a) cin>>x;
    int e1=0,e2=1,c1=0,c2=0;
    for(int x:a){
        if(x==e1) c1++;
        else if(x==e2) c2++;
        else if(!c1){e1=x;c1=1;}
        else if(!c2){e2=x;c2=1;}
        else{c1--;c2--;}
    }
    c1=c2=0;
    for(int x:a){if(x==e1)c1++;else if(x==e2)c2++;}
    vector<int> res;
    if(c1>n/3) res.push_back(e1);
    if(c2>n/3) res.push_back(e2);
    for(int i=0;i<(int)res.size();i++) cout<<res[i]<<" \n"[i+1==(int)res.size()];
    if(res.empty()) cout<<"\n";
}
