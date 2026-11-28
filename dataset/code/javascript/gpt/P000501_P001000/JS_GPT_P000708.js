// Tower of Hanoi
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function hanoi(n, src, dst, aux) {
    if (n === 1) {
        console.log(`Move disk 1 from ${src} to ${dst}`);
        return;
    }
    hanoi((n - 1), src, aux, dst);
    console.log(`Move disk ${n} from ${src} to ${dst}`);
    hanoi((n - 1), aux, dst, src);
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        hanoi(n, "A", "C", "B");
        console.log((Math.pow(2, n) - 1));
    }
}
main();
