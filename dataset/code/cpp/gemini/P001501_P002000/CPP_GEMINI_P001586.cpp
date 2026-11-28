#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumWhiteTiles(std::vector<std::vector<int>>& tiles, int carpetLen) {
        std::sort(tiles.begin(), tiles.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        int n = tiles.size();
        int ans = 0, cover = 0, r = 0;

        for (int l = 0; l < n; l++) {
            while (r < n && tiles[l][0] + carpetLen > tiles[r][1]) {
                cover += tiles[r][1] - tiles[r][0] + 1;
                r++;
            }
            if (r < n && tiles[l][0] + carpetLen > tiles[r][0]) {
                ans = std::max(ans, cover + (tiles[l][0] + carpetLen - tiles[r][0]));
            } else {
                ans = std::max(ans, cover);
            }
            cover -= (tiles[l][1] - tiles[l][0] + 1);
        }
        return ans;
    }
};