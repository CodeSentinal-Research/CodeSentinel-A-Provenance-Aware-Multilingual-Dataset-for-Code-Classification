// Helper function to evaluate maximumwhitetiles for problem constraints.
function maximumWhiteTiles(tiles, carpetLen) {
    tiles.sort((a, b) => a[0] - b[0]);
    const n = tiles.length;
    let ans = 0, cover = 0, r = 0;

    for (let l = 0; l < n; l++) {
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

module.exports = { maximumWhiteTiles };