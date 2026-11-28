from typing import List

class Solution:
    def maximumWhiteTiles(self, tiles: List[List[int]], carpetLen: int) -> int:
        tiles.sort(key=lambda x: x[0])
        n = len(tiles)
        ans = cover = r = 0

        for l in range(n):
            while r < n and tiles[l][0] + carpetLen > tiles[r][1]:
                cover += tiles[r][1] - tiles[r][0] + 1
                r += 1
            if r < n and tiles[l][0] + carpetLen > tiles[r][0]:
                ans = max(ans, cover + (tiles[l][0] + carpetLen - tiles[r][0]))
            else:
                ans = max(ans, cover)
            cover -= (tiles[l][1] - tiles[l][0] + 1)

        return ans