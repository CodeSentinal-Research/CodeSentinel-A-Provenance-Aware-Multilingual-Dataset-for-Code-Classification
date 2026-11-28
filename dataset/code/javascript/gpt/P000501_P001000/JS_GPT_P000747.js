// Count Ways to Climb Stairs
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function climb_stairs(n) {
    if (n <= 1) {
        return 1;
    }
    let [a, b] = [1, 1];
    for (const _ of Array.from({length: ((n + 1)) - (2)}, (_, i) => (2) + i)) {
        [a, b] = [b, (a + b)];
    }
    return b;
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        console.log(climb_stairs(n));
    }
}
main();
