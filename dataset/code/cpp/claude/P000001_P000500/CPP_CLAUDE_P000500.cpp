#include <iostream>
#include <string>
using namespace std;
class Solution{
public:
    int minOperations(vector<string>& logs){
        int depth=0;
        for(auto& op:logs){
            if(op=="../"){if(depth>0)depth--;}
            else if(op!="./") depth++;
        }
        return depth;
    }
};
int main(){
    int n;cin>>n;
    vector<string> logs(n);
    for(auto& s:logs) cin>>s;
    cout<<Solution().minOperations(logs)<<"\n";
}
