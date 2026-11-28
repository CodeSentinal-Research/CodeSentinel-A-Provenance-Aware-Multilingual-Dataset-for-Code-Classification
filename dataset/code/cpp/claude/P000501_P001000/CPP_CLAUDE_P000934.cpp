#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& A) {
        int n=A.size();
        for(int i=0;i<n/2;i++) for(int j=i;j<n-1-i;j++){
            int t=A[i][j];
            A[i][j]=A[n-1-j][i];
            A[n-1-j][i]=A[n-1-i][n-1-j];
            A[n-1-i][n-1-j]=A[j][n-1-i];
            A[j][n-1-i]=t;
        }
    }
};
int main() {
    int n; cin>>n;
    vector<vector<int>> A(n,vector<int>(n));
    for(auto& row:A) for(auto& x:row) cin>>x;
    Solution().rotate(A);
    for(auto& row:A){for(int i=0;i<(int)row.size();i++) cout<<row[i]<<(i+1<(int)row.size()?" ":"\n");}
}
