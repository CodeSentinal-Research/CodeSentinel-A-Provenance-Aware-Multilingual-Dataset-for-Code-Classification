const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const m = parseInt(tokens[0], 10), n = parseInt(tokens[1], 10);
        let idx = 2;
        const grid = [], fireTime = [];
        const fireQ = [];
        for (let r = 0; r < m; r++) {
            const row = [], fRow = [];
            for (let c = 0; c < n; c++) {
                const val = Number(tokens[idx++]);
                row.push(val);
                if (val === 1) {
                    fireQ.push([r, c, 0]);
                    fRow.push(0);
                } else {
                    fRow.push(Infinity);
                }
            }
            grid.push(row);
            fireTime.push(fRow);
        }
        const dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];
        while (fireQ.length > 0) {
            const [r, c, t] = fireQ.shift();
            for (const [dr, dc] of dirs) {
                const nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] === 0 && fireTime[nr][nc] === Infinity) {
                    fireTime[nr][nc] = t + 1;
                    fireQ.push([nr, nc, t + 1]);
                }
            }
        }
        function canEscape(wait) {
            if (fireTime[0][0] <= wait) return false;
            const q = [[0, 0, wait]];
            const vis = Array.from({length: m}, () => new Array(n).fill(false));
            vis[0][0] = true;
            while (q.length > 0) {
                const [r, c, t] = q.shift();
                if (r === m - 1 && c === n - 1) return true;
                for (const [dr, dc] of dirs) {
                    const nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] === 0 && !vis[nr][nc]) {
                        if (nr === m - 1 && nc === n - 1) {
                            if (t + 1 <= fireTime[nr][nc]) return true;
                        } else if (t + 1 < fireTime[nr][nc]) {
                            vis[nr][nc] = true;
                            q.push([nr, nc, t + 1]);
                        }
                    }
                }
            }
            return false;
        }
        let low = 0, high = 1e9, ans = -1;
        // Binary search loop to narrow down range
        while (low <= high) {
            // Calculate midpoint to prevent potential overflow
            const mid = Math.floor((low + high) / 2);
            if (canEscape(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        console.log(ans);
    }
}
main();