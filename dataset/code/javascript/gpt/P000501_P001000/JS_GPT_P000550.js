// Circular Tour
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let petrol = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let distance = Array.from(tokens.slice((1 + n), (1 + (2 * n))).map(Number));
        let total_surplus = 0;
        let curr_surplus = 0;
        let start = 0;
        for (const i of Array.from({length: n}, (_, i) => i)) {
            let diff = (petrol[i] - distance[i]);
            total_surplus += diff;
            curr_surplus += diff;
            if (curr_surplus < 0) {
                start = (i + 1);
                curr_surplus = 0;
            }
        }
        console.log((total_surplus >= 0 ? start : -(1)));
    }
}
main();
