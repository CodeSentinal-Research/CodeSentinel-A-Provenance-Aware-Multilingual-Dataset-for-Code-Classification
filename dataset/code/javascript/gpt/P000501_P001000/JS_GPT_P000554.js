// Nearest Exit from Maze
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let m = parseInt(tokens[0], 10);
        let n = parseInt(tokens[1], 10);
        let maze = tokens.slice(2, (2 + m));
        let er = parseInt(tokens[(2 + m)], 10);
        let ec = parseInt(tokens[(3 + m)], 10);
        let q = deque([[er, ec, 0]]);
        let visited = new Set([[er, ec]]);
        let dirs = [[-(1), 0], [1, 0], [0, -(1)], [0, 1]];
        while (q) {
            let [r, c, d] = q.popleft();
            if (((r !== er || c !== ec) && (r === 0 || r === (m - 1) || c === 0 || c === (n - 1)))) {
                console.log(d);
                return;
            }
            for (const [dr, dc] of dirs) {
                let [nr, nc] = [(r + dr), (c + dc)];
                if ((0 <= nr && nr < m && 0 <= nc && nc < n && maze[nr][nc] === "." && !_in([nr, nc], visited))) {
                    visited.add([nr, nc]);
                    q.push([nr, nc, (d + 1)]);
                }
            }
        }
        console.log(-(1));
    }
}
main();
