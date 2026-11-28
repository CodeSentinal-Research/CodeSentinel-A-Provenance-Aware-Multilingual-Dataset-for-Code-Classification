#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main(){
    int n; cin>>n;
    unordered_set<int> s;
    for(int i=0;i<n;i++){int x;cin>>x;s.insert(x);}
    int best=0;
    for(int x:s){
        if(!s.count(x-1)){
            int cur=1;
            while(s.count(x+cur)) cur++;
            best=max(best,cur);
        }
    }
    cout<<best<<"\n";
}
