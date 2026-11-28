// Generate Binary Numbers
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let res = [...Array.from({length: ((n + 1)) - (1)}, (_, i) => (1) + i)].map(i => bin(i).slice(2));
        console.log(...res);
    }
}
main();
