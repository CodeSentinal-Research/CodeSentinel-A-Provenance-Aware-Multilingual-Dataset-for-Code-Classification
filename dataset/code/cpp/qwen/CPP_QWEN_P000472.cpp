#include <iostream>
#include <vector>
using namespace std;
int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> mat(r, vector<int>(c));
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) cin >> mat[i][j];
    int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) {
        bool is_peak = true;
        for(int d=0; d<4; d++) {
            int nx=i+dx[d], ny=j+dy[d];
            if(nx>=0 && nx<r && ny>=0 && ny<c && mat[nx][ny]>=mat[i][j]) is_peak = false;
        }
        if(is_peak) { cout << mat[i][j] << endl; return 0; }
    }
    return 0;
}
