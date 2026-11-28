// Escape the Spreading Fire
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let m = parseInt(tokens[0], 10);
        let n = parseInt(tokens[1], 10);
        let idx = 2;
        let grid = [];
        let fire_q = deque();
        let fire_time = [...Array.from({length: m}, (_, i) => i)].map(_ => ([parseFloat("inf")] * n));
        for (const r of Array.from({length: m}, (_, i) => i)) {
            let row = [];
            for (const c of Array.from({length: n}, (_, i) => i)) {
                let val = parseInt(tokens[idx], 10);
                row.push(val);
                if (val === 1) {
                    fire_q.push([r, c, 0]);
                    fire_time[r][c] = 0;
                }
                idx += 1;
            }
            grid.push(row);
        }
        let dirs = [[-(1), 0], [1, 0], [0, -(1)], [0, 1]];
        while (fire_q) {
            let [r, c, t] = fire_q.popleft();
            for (const [dr, dc] of dirs) {
                let [nr, nc] = [(r + dr), (c + dc)];
                if ((0 <= nr && nr < m && 0 <= nc && nc < n && grid[nr][nc] === 0 && fire_time[nr][nc] === parseFloat("inf"))) {
                    fire_time[nr][nc] = (t + 1);
                    fire_q.push([nr, nc, (t + 1)]);
                }
            }
        }
        function can_escape(wait_time) {
            if (fire_time[0][0] <= wait_time) {
                return false;
            }
            let q = deque([[0, 0, wait_time]]);
            let visited = [...Array.from({length: m}, (_, i) => i)].map(_ => ([false] * n));
            visited[0][0] = true;
            while (q) {
                [r, c, t] = q.popleft();
                if ((r === (m - 1) && c === (n - 1))) {
                    return true;
                }
                for (const [dr, dc] of dirs) {
                    [nr, nc] = [(r + dr), (c + dc)];
                    if ((0 <= nr && nr < m && 0 <= nc && nc < n && grid[nr][nc] === 0 && !(visited[nr][nc]))) {
                        if ((nr === (m - 1) && nc === (n - 1))) {
                            if ((t + 1) <= fire_time[nr][nc]) {
                                return true;
                            }
                        } else {
                            if ((t + 1) < fire_time[nr][nc]) {
                                visited[nr][nc] = true;
                                q.push([nr, nc, (t + 1)]);
                            }
                        }
                    }
                }
            }
            return false;
        }
        let [low, high] = [0, Math.pow(10, 9)];
        let ans = -(1);
        while (low <= high) {
            let mid = Math.floor((low + high) / 2);
            if (can_escape(mid)) {
                ans = mid;
                low = (mid + 1);
            } else {
                high = (mid - 1);
            }
        }
        console.log(ans);
    }
}
main();
