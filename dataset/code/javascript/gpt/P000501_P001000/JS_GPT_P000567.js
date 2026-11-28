// Cut Off Trees for Golf Event
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
        let idx = 2;
        let forest = [];
        let trees = [];
        for (const r of Array.from({length: m}, (_, i) => i)) {
            let row = [];
            for (const c of Array.from({length: n}, (_, i) => i)) {
                let val = parseInt(tokens[idx], 10);
                row.push(val);
                if (val > 1) {
                    trees.push([val, r, c]);
                }
                idx += 1;
            }
            forest.push(row);
        }
        trees.sort();
        function bfs(sr, sc, tr, tc) {
            if ((sr === tr && sc === tc)) {
                return 0;
            }
            let q = deque([[sr, sc, 0]]);
            let vis = new Set([[sr, sc]]);
            while (q) {
                let [r, c, d] = q.popleft();
                for (const [dr, dc] of [[-(1), 0], [1, 0], [0, -(1)], [0, 1]]) {
                    let [nr, nc] = [(r + dr), (c + dc)];
                    if ((0 <= nr && nr < m && 0 <= nc && nc < n && forest[nr][nc] !== 0 && !_in([nr, nc], vis))) {
                        if ((nr === tr && nc === tc)) {
                            return (d + 1);
                        }
                        vis.add([nr, nc]);
                        q.push([nr, nc, (d + 1)]);
                    }
                }
            }
            return -(1);
        }
        let total_steps = 0;
        let [cur_r, cur_c] = [0, 0];
        for (const [val, tr, tc] of trees) {
            let steps = bfs(cur_r, cur_c, tr, tc);
            if (steps === -(1)) {
                console.log(-(1));
                return;
            }
            total_steps += steps;
            [cur_r, cur_c] = [tr, tc];
        }
        console.log(total_steps);
    }
}
main();
