// First Unique Number
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let q_count = parseInt(tokens[(1 + n)], 10);
        let idx = (2 + n);
        let count = Counter(nums);
        let q = Array.from(nums);
        for (const _ of Array.from({length: q_count}, (_, i) => i)) {
            let cmd = tokens[idx];
            if (cmd === "showFirstUnique") {
                while ((q && count[q[0]] > 1)) {
                    q.splice(0, 1)[0];
                }
                console.log((q ? q[0] : -(1)));
                idx += 1;
            } else {
                if (cmd === "add") {
                    let val = parseInt(tokens[(idx + 1)], 10);
                    count[val] += 1;
                    q.push(val);
                    idx += 2;
                }
            }
        }
    }
}
main();
