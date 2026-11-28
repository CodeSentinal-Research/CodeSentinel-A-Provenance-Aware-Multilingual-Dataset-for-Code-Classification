#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<long long>> add(vector<vector<long long>>& A, vector<vector<long long>>& B) {
        int r=A.size(), c=A[0].size();
        vector<vector<long long>> C(r, vector<long long>(c));
        for(int i=0;i<r;i++) for(int j=0;j<c;j++) C[i][j]=A[i][j]+B[i][j];
        return C;
    }
};
int main() {
    int r,c; cin>>r>>c;
    vector<vector<long long>> A(r,vector<long long>(c)),B(r,vector<long long>(c));
    for(auto& row:A) for(auto& x:row) cin>>x;
    for(auto& row:B) for(auto& x:row) cin>>x;
    auto C=Solution().add(A,B);
    for(auto& row:C){for(int i=0;i<(int)row.size();i++) cout<<row[i]<<(i+1<(int)row.size()?" ":"\n");}
}
