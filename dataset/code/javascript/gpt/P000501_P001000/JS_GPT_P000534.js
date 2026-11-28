// Dota2 Senate
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let s = _stdin_all.trim();
    if (s) {
        let n = (s.length !== undefined ? s.length : s.size);
        let r_q = [...[...s].map((v, i) => [i, v])].filter(([i, c]) => c === "R").map(([i, c]) => i);
        let d_q = [...[...s].map((v, i) => [i, v])].filter(([i, c]) => c === "D").map(([i, c]) => i);
        while ((r_q && d_q)) {
            let r_idx = r_q.splice(0, 1)[0];
            let d_idx = d_q.splice(0, 1)[0];
            if (r_idx < d_idx) {
                r_q.push((r_idx + n));
            } else {
                d_q.push((d_idx + n));
            }
        }
        console.log((r_q ? "Radiant" : "Dire"));
    }
}
main();
