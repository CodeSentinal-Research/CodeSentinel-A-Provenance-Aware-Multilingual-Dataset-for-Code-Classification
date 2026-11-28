// Beautiful Arrangement
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function count_arrangements(n) {
    let used = ([false] * (n + 1));
    function backtrack(pos) {
        if (pos > n) {
            return 1;
        }
        let count = 0;
        for (const i of Array.from({length: ((n + 1)) - (1)}, (_, i) => (1) + i)) {
            if ((!(used[i]) && ((i % pos) === 0 || (pos % i) === 0))) {
                used[i] = true;
                count += backtrack((pos + 1));
                used[i] = false;
            }
        }
        return count;
    }
    return backtrack(1);
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        console.log(count_arrangements(n));
    }
}
main();
