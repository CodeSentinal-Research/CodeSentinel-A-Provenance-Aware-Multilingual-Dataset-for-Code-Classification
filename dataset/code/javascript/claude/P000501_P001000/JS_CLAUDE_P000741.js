function floodFill(image, sr, sc, color) {
    const original = image[sr][sc];
    if (original === color) return image;
    const rows = image.length, cols = image[0].length;
    const dx = [0, 0, 1, -1], dy = [1, -1, 0, 0];
    function dfs(r, c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || image[r][c] !== original) return;
        image[r][c] = color;
        for (let d = 0; d < 4; d++) dfs(r + dx[d], c + dy[d]);
    }
    dfs(sr, sc);
    return image;
}

module.exports = { floodFill };
