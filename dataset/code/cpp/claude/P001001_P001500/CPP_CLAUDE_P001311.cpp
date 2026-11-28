#include <iostream>
#include <vector>
using namespace std;
class Solution{
    int n, cnt=0;
    vector<int> col,d1,d2;
    void solve(int row){
        if(row==n){cnt++;return;}
        for(int c=0;c<n;c++)
            if(!col[c]&&!d1[row-c+n]&&!d2[row+c]){
                col[c]=d1[row-c+n]=d2[row+c]=1;
                solve(row+1);
                col[c]=d1[row-c+n]=d2[row+c]=0;
            }
    }
public:
    int totalNQueens(int n_){
        n=n_;col.assign(n,0);d1.assign(2*n,0);d2.assign(2*n,0);
        solve(0); return cnt;
    }
};
int main(){
    int n;cin>>n;
    cout<<Solution().totalNQueens(n)<<"\n";
}
