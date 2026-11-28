// Generate All Valid Abbreviations of a Word
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function get_abbrevs(word) {
    let res = [];
    function backtrack(idx, cur, count) {
        if (idx === (word.length !== undefined ? word.length : word.size)) {
            res.push((cur + (count > 0 ? String(count) : "")));
            return;
        }
        backtrack((idx + 1), cur, (count + 1));
        backtrack((idx + 1), ((cur + (count > 0 ? String(count) : "")) + word[idx]), 0);
    }
    backtrack(0, "", 0);
    return [...res].sort((a, b) => a < b ? -1 : a > b ? 1 : 0);
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        for (const abbr of get_abbrevs(tokens[0])) {
            console.log(abbr);
        }
    }
}
main();
