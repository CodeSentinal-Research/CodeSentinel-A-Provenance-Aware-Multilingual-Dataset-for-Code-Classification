#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    long long diagonalSum(vector<vector<int>>& A) {
        int n=A.size(); long long s=0;
        for(int i=0;i<n;i++){
            s+=A[i][i];
            if(i!=n-1-i) s+=A[i][n-1-i];
        }
        return s;
    }
};
int main() {
    int n; cin>>n;
    vector<vector<int>> A(n,vector<int>(n));
    for(auto& row:A) for(auto& x:row) cin>>x;
    cout<<Solution().diagonalSum(A)<<"\n";
}
