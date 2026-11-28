#include <iostream>
#include <vector>
using namespace std;
int main() {
    int r, c, target; cin >> r >> c >> target;
    vector<vector<int>> mat(r, vector<int>(c));
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) cin >> mat[i][j];
    int i=0, j=c-1, found=0;
    while(i<r && j>=0) {
        if(mat[i][j]==target) { found=1; break; }
        else if(mat[i][j]>target) j--; else i++;
    }
    cout << (found ? "Found" : "Not Found") << endl;
    return 0;
}
