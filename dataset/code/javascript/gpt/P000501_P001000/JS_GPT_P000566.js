// Minimum Genetic Mutation
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let start_gene = tokens[0];
        let end_gene = tokens[1];
        let n = parseInt(tokens[2], 10);
        let bank = new Set(tokens.slice(3, (3 + n)));
        if (!_in(end_gene, bank)) {
            console.log(-(1));
            return;
        }
        let q = deque([[start_gene, 0]]);
        let visited = new Set([start_gene]);
        while (q) {
            let [gene, step] = q.popleft();
            if (gene === end_gene) {
                console.log(step);
                return;
            }
            for (const i of Array.from({length: 8}, (_, i) => i)) {
                for (const c of "ACGT") {
                    let nxt = ((gene.slice(0, i) + c) + gene.slice((i + 1)));
                    if ((_in(nxt, bank) && !_in(nxt, visited))) {
                        visited.add(nxt);
                        q.push([nxt, (step + 1)]);
                    }
                }
            }
        }
        console.log(-(1));
    }
}
main();
