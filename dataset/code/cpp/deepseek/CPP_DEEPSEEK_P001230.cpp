#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int dr[] = {0, 1, 0, -1};
int dc[] = {-1, 0, 1, 0};

int countPaths(int r, int c, int k, int sr, int sc) {
    vector<vector<int>> grid(r, vector<int>(c, -1));
    deque<pair<int, int>> dq;
    dq.push_back({sr, sc});
    grid[sr][sc] = 0;
    
    while(!dq.empty()) {
        int cr = dq.front().first;
        int cc = dq.front().second;
        dq.pop_front();
        
        for(int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if(nr < 0 || nc < 0 || nr >= r || nc >= c || grid[nr][nc] != -1) continue;
            
            if(abs(nr - cr) + abs(nc - cc) <= k) {
                dq.push_back({nr, nc});
                grid[nr][nc] = grid[cr][cc] + 1;
            }
        }
    }
    
    int count = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(grid[i][j] == -1 || grid[i][j] > k) continue;
            count++;
        }
    }
    return count;
}

int main() {
    int r, c, k;
    cin >> r >> c >> k;
    int sr, sc;
    cin >> sr >> sc;
    cout << countPaths(r, c, k, sr, sc) << endl;
    return 0;
}
This code first creates a grid with the given dimensions and a queue to store the cells to visit. The cell's coordinates are initialized in the main function and are popped from the queue in a breadth-first manner. Each cell is visited and all the valid neighbours are added to the queue. If the distance to the neighbour is less than or equal to k, the neighbour's coordinates are added to the queue. The count of valid paths is incremented each time a valid path is found.