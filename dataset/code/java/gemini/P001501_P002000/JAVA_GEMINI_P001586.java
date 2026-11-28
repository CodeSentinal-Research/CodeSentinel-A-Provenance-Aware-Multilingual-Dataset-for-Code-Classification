import java.util.Arrays;

public class Solution {
    public int maximumWhiteTiles(int[][] tiles, int carpetLen) {
        Arrays.sort(tiles, (a, b) -> a[0] - b[0]);
        int n = tiles.length;
        int ans = 0, cover = 0, r = 0;

        for (int l = 0; l < n; l++) {
            while (r < n && tiles[l][0] + carpetLen > tiles[r][1]) {
                cover += tiles[r][1] - tiles[r][0] + 1;
                r++;
            }
            if (r < n && tiles[l][0] + carpetLen > tiles[r][0]) {
                ans = Math.max(ans, cover + (tiles[l][0] + carpetLen - tiles[r][0]));
            } else {
                ans = Math.max(ans, cover);
            }
            cover -= (tiles[l][1] - tiles[l][0] + 1);
        }
        return ans;
    }
}