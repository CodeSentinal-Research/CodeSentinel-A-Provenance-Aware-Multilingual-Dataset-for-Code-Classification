#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];
            
    map<vector<int>, int> rowMap;
    map<vector<int>, int> colMap;
    
    for (int i = 0; i < n; ++i) {
        rowMap[mat[i]]++;
        vector<int> col(n);
        for (int j = 0; j < n; ++j) col[j] = mat[j][i];
        colMap[col]++;
    }
    
    long long pairs = 0;
    for (auto& p : rowMap) {
        if (colMap.find(p.first) != colMap.end()) {
            pairs += (long long)p.second * colMap[p.first];
        }
    }
    
    cout << pairs << endl;
    return 0;
}
