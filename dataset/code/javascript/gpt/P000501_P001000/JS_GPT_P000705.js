// Generate All Subsequences of an Array
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function gen_subseq(arr, idx, cur) {
    if (idx === (arr.length !== undefined ? arr.length : arr.size)) {
        console.log(...cur);
        return;
    }
    gen_subseq(arr, (idx + 1), cur);
    gen_subseq(arr, (idx + 1), (cur + [arr[idx]]));
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        gen_subseq(nums, 0, []);
    }
}
main();
