#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
    int r,c; cin>>r>>c;
    vector<vector<int>> A(r,vector<int>(c));
    for(auto&row:A) for(auto&x:row) cin>>x;
    long long best=LLONG_MIN;
    for(int i=0;i+2<r;i++) for(int j=0;j+2<c;j++){
        long long s=A[i][j]+A[i][j+1]+A[i][j+2]+A[i+1][j+1]+A[i+2][j]+A[i+2][j+1]+A[i+2][j+2];
        best=max(best,s);
    }
    cout<<best<<"\n";
}
