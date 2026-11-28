const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const grid = tokens.slice(1, 1 + n).map(r => r.split(''));
        const wCnt = parseInt(tokens[1 + n], 10);
        const words = tokens.slice(2 + n, 2 + n + wCnt);
        function canPlaceH(r, c, w) {
            if (c + w.length > n) return false;
            for (let i = 0; i < w.length; i++) {
                if (grid[r][c + i] !== '-' && grid[r][c + i] !== w[i]) return false;
            }
            return true;
        }
        function placeH(r, c, w) {
            const placed = [];
            for (let i = 0; i < w.length; i++) {
                if (grid[r][c + i] === '-') {
                    grid[r][c + i] = w[i];
                    placed.push([r, c + i]);
                }
            }
            return placed;
        }
        function canPlaceV(r, c, w) {
            if (r + w.length > n) return false;
            for (let i = 0; i < w.length; i++) {
                if (grid[r + i][c] !== '-' && grid[r + i][c] !== w[i]) return false;
            }
            return true;
        }
        function placeV(r, c, w) {
            const placed = [];
            for (let i = 0; i < w.length; i++) {
                if (grid[r + i][c] === '-') {
                    grid[r + i][c] = w[i];
                    placed.push([r + i, c]);
                }
            }
            return placed;
        }
        function unplace(placed) {
            for (const [r, c] of placed) grid[r][c] = '-';
        }
        function backtrack(idx) {
            if (idx === words.length) return true;
            const w = words[idx];
            for (let r = 0; r < n; r++) {
                for (let c = 0; c < n; c++) {
                    if (canPlaceH(r, c, w)) {
                        const placed = placeH(r, c, w);
                        if (backtrack(idx + 1)) return true;
                        unplace(placed);
                    }
                    if (canPlaceV(r, c, w)) {
                        const placed = placeV(r, c, w);
                        if (backtrack(idx + 1)) return true;
                        unplace(placed);
                    }
                }
            }
            return false;
        }
        backtrack(0);
        for (const row of grid) console.log(row.join(''));
    }
}
main();