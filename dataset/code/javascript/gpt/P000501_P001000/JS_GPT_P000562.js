// Keys and Rooms
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let idx = 1;
        let rooms = [];
        for (const _ of Array.from({length: n}, (_, i) => i)) {
            let k = parseInt(tokens[idx], 10);
            rooms.push(Array.from(tokens.slice((idx + 1), ((idx + 1) + k)).map(Number)));
            idx += (1 + k);
        }
        let visited = new Set([0]);
        let q = deque([0]);
        while (q) {
            let room = q.popleft();
            for (const key of rooms[room]) {
                if (!_in(key, visited)) {
                    visited.add(key);
                    q.push(key);
                }
            }
        }
        console.log(((visited.length !== undefined ? visited.length : visited.size) === n ? "true" : "false"));
    }
}
main();
