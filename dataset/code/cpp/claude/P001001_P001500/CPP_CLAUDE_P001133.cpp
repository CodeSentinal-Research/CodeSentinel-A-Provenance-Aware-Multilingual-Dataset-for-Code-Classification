#include <iostream>
using namespace std;
class Solution{
public:
    long long climbStairs(int n){
        if(n<=2) return n;
        long long a=1,b=2;
        for(int i=3;i<=n;i++){long long c=a+b;a=b;b=c;}
        return b;
    }
};
int main(){
    int n;cin>>n;
    cout<<Solution().climbStairs(n)<<"\n";
}
