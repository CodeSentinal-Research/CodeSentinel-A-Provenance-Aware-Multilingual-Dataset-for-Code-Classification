// Open the Lock
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let d = parseInt(tokens[0], 10);
        let deadends = new Set(tokens.slice(1, (1 + d)));
        let target = tokens[(1 + d)];
        if (_in("0000", deadends)) {
            console.log(-(1));
            return;
        }
        if (target === "0000") {
            console.log(0);
            return;
        }
        let q = deque([["0000", 0]]);
        let visited = new Set(deadends);
        visited.add("0000");
        while (q) {
            let [cur, dist] = q.popleft();
            if (cur === target) {
                console.log(dist);
                return;
            }
            for (const i of Array.from({length: 4}, (_, i) => i)) {
                let digit = parseInt(cur[i], 10);
                for (const diff of [-(1), 1]) {
                    let nxt_digit = ((digit + diff) % 10);
                    let nxt = ((cur.slice(0, i) + String(nxt_digit)) + cur.slice((i + 1)));
                    if (!_in(nxt, visited)) {
                        visited.add(nxt);
                        q.push([nxt, (dist + 1)]);
                    }
                }
            }
        }
        console.log(-(1));
    }
}
main();
