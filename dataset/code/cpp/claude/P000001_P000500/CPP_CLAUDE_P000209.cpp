#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; cin>>n;
    vector<vector<int>> A(n,vector<int>(n));
    for(auto&row:A) for(auto&x:row) cin>>x;
    for(int layer=0;layer<n/2;layer++){
        int first=layer,last=n-1-layer;
        for(int i=first;i<last;i++){
            int off=i-first;
            int top=A[first][i];
            A[first][i]=A[last-off][first];
            A[last-off][first]=A[last][last-off];
            A[last][last-off]=A[first+off][last];
            A[first+off][last]=top;
        }
    }
    for(int i=0;i<n;i++){for(int j=0;j<n;j++) cout<<A[i][j]<<" \n"[j==n-1];}
}
