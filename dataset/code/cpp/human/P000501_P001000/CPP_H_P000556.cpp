// 6353. Minimum Number of Visited Cells in a Grid
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dist(m*n, 1e9);
        dist[0] = 0;
        priority_queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int cell = q.top();
            q.pop();
            int i = cell/n;
            int j = cell%n;
            // down 
            for(int k = i+1; k <= min(m-1, grid[i][j] + i); k++) {
                if(dist[k*n + j] > dist[cell] + 1) {
                    dist[k*n + j] = dist[cell] + 1;
                    q.push(k*n + j);
                }
            }
            // right
            for(int k = j+1; k <= min(n-1, grid[i][j] + j); k++) {
                if(dist[i*n + k] > dist[cell] + 1) {
                    dist[i*n + k] = dist[cell] + 1;
                    q.push(i*n + k);
                }
            }
        }   
        return dist[m*n -1] == 1e9 ? -1: dist[m*n -1]+1;   
    }
};

int main() {
    Solution obj;
    vector<vector<int>> grid = {
    {3,4,2,1},{4,2,3,1},{2,1,0,0},{2,4,0,0}
    };
    cout<<obj.minimumVisitedCells(grid)<<endl;
    
    return 0;
}