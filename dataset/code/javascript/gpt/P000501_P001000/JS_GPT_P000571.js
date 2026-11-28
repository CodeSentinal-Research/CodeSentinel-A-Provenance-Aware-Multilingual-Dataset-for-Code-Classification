// Hot Potato Game
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let k = parseInt(tokens[1], 10);
        let ans = 0;
        for (const i of Array.from({length: ((n + 1)) - (1)}, (_, i) => (1) + i)) {
            ans = ((ans + k) % i);
        }
        console.log((ans + 1));
    }
}
main();
