// Reveal Cards in Increasing Order
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let deck = [...Array.from(tokens.slice(1, (1 + n)).map(Number))].sort((a, b) => a < b ? -1 : a > b ? 1 : 0);
        let q = Array.from(Array.from({length: n}, (_, i) => i));
        let res = ([0] * n);
        for (const card of deck) {
            res[q.splice(0, 1)[0]] = card;
            if (q) {
                q.push(q.splice(0, 1)[0]);
            }
        }
        console.log(...res);
    }
}
main();
