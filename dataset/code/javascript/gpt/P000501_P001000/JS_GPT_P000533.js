// Moving Average from Data Stream
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let size = parseInt(tokens[0], 10);
        let q = parseInt(tokens[1], 10);
        let stream = Array.from(tokens.slice(2, (2 + q)).map(Number));
        let window = [];
        let window_sum = 0;
        for (const val of stream) {
            window.push(val);
            window_sum += val;
            if ((window.length !== undefined ? window.length : window.size) > size) {
                window_sum -= window.splice(0, 1)[0];
            }
            console.log(`${(window_sum / (window.length !== undefined ? window.length : window.size))}`);
        }
    }
}
main();
