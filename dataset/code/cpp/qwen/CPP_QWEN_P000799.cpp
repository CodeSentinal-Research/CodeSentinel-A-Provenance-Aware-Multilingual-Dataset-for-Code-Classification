#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> grid[i][j];
            
    vector<vector<long long>> prefix(N + 1, vector<long long>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            prefix[i][j] = grid[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (j > 1) cout << " ";
            cout << prefix[i][j];
        }
        cout << endl;
    }
    return 0;
}
