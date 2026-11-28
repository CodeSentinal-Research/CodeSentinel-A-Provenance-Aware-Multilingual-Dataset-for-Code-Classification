// Letter Combinations of a Phone Number
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
let mapping = {["2"]: "abc", ["3"]: "def", ["4"]: "ghi", ["5"]: "jkl", ["6"]: "mno", ["7"]: "pqrs", ["8"]: "tuv", ["9"]: "wxyz"};
function letter_comb(digits, idx, cur) {
    if (idx === (digits.length !== undefined ? digits.length : digits.size)) {
        console.log(cur);
        return;
    }
    for (const c of mapping[digits[idx]]) {
        letter_comb(digits, (idx + 1), (cur + c));
    }
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let digits = tokens[0];
        letter_comb(digits, 0, "");
    }
}
main();
