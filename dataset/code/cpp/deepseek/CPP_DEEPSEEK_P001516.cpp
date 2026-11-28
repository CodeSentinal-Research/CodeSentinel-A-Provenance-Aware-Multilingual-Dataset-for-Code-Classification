#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, CarpetLength;
    cin >> N >> CarpetLength;
    vector<pair<int, int>> tiles(N);
    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        tiles[i] = make_pair(start, end);
    }
    sort(tiles.begin(), tiles.end());
    int maxCovered = 0;
    int currentEnd = 0;
    for (int i = 0; i < N; i++) {
        if (tiles[i].first <= currentEnd) {
            maxCovered = max(maxCovered, tiles[i].second);
        } else {
            currentEnd = tiles[i].second;
       
        }
    }
    cout << maxCovered << endl;
    return 0;
}
This code reads the number of white tiles and the length of the carpet, then reads the intervals of the tiles. The tiles are sorted by their start position. The code then iterates over the sorted tiles, updating the maximum number of white tiles that can be covered by the carpet if the current tile starts before the end of the previous tile. If the current tile starts after the end of the previous tile, it simply updates the end of the current tile to be the end of the previous tile. The maximum number of covered tiles is then printed out.