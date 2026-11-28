#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<long long>> multiply(vector<vector<long long>>& A, vector<vector<long long>>& B) {
        int r1=A.size(), c1=A[0].size(), c2=B[0].size();
        vector<vector<long long>> C(r1, vector<long long>(c2, 0));
        for (int i=0;i<r1;i++) for (int j=0;j<c2;j++) for (int k=0;k<c1;k++) C[i][j]+=A[i][k]*B[k][j];
        return C;
    }
};
int main() {
    int r1,c1,r2,c2; cin>>r1>>c1>>r2>>c2;
    vector<vector<long long>> A(r1,vector<long long>(c1)),B(r2,vector<long long>(c2));
    for(auto& row:A) for(auto& x:row) cin>>x;
    for(auto& row:B) for(auto& x:row) cin>>x;
    auto C=Solution().multiply(A,B);
    for(auto& row:C){for(int i=0;i<(int)row.size();i++) cout<<row[i]<<(i+1<(int)row.size()?" ":"\n");}
}
