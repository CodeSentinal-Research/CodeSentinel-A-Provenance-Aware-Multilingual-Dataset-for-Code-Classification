// Matrix Cells in Distance Order
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let rows = parseInt(tokens[0], 10);
        let cols = parseInt(tokens[1], 10);
        let r0 = parseInt(tokens[2], 10);
        let c0 = parseInt(tokens[3], 10);
        let cells = [...Array.from({length: rows}, (_, i) => i)].map(r => [r, c]);
        cells.sort();
        for (const [r, c] of cells) {
            console.log(`[${r},${c}]`);
        }
        console.log();
    }
}
main();
