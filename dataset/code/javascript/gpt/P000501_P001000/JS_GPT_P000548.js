// Bus Routes
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let r = parseInt(tokens[0], 10);
        let idx = 1;
        let routes = [];
        let stop_to_routes = defaultdict(list);
        for (const bus of Array.from({length: r}, (_, i) => i)) {
            let k = parseInt(tokens[idx], 10);
            let route = Array.from(tokens.slice((idx + 1), ((idx + 1) + k)).map(Number));
            routes.push(route);
            for (const stop of route) {
                stop_to_routes[stop].push(bus);
            }
            idx += (1 + k);
        }
        let source = parseInt(tokens[idx], 10);
        let target = parseInt(tokens[(idx + 1)], 10);
        if (source === target) {
            console.log(0);
            return;
        }
        let q = deque([[source, 0]]);
        let visited_stops = new Set([source]);
        let visited_routes = new Set();
        while (q) {
            let [stop, buses] = q.popleft();
            for (const bus of stop_to_routes[stop]) {
                if (!_in(bus, visited_routes)) {
                    visited_routes.add(bus);
                    for (const nxt_stop of routes[bus]) {
                        if (nxt_stop === target) {
                            console.log((buses + 1));
                            return;
                        }
                        if (!_in(nxt_stop, visited_stops)) {
                            visited_stops.add(nxt_stop);
                            q.push([nxt_stop, (buses + 1)]);
                        }
                    }
                }
            }
        }
        console.log(-(1));
    }
}
main();
