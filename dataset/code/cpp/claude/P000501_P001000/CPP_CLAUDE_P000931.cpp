#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int r=A.size(), c=A[0].size();
        vector<vector<int>> T(c, vector<int>(r));
        for(int i=0;i<r;i++) for(int j=0;j<c;j++) T[j][i]=A[i][j];
        return T;
    }
};
int main() {
    int r,c; cin>>r>>c;
    vector<vector<int>> A(r,vector<int>(c));
    for(auto& row:A) for(auto& x:row) cin>>x;
    auto T=Solution().transpose(A);
    for(auto& row:T){for(int i=0;i<(int)row.size();i++) cout<<row[i]<<(i+1<(int)row.size()?" ":"\n");}
}
