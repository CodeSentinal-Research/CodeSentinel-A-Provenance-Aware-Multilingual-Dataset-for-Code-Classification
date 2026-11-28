// Word Break II
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function word_break(s, word_dict) {
    let words = new Set(word_dict);
    let memo = {};
    function backtrack(idx) {
        if (_in(idx, memo)) {
            return memo[idx];
        }
        if (idx === (s.length !== undefined ? s.length : s.size)) {
            return [""];
        }
        let res = [];
        for (const end of Array.from({length: (((s.length !== undefined ? s.length : s.size) + 1)) - ((idx + 1))}, (_, i) => ((idx + 1)) + i)) {
            let w = s.slice(idx, end);
            if (_in(w, words)) {
                let sub = backtrack(end);
                for (const sent of sub) {
                    res.push(((w + " ") + sent).trim());
                }
            }
        }
        memo[idx] = res;
        return res;
    }
    let ans = backtrack(0);
    return [...ans].sort((a, b) => a < b ? -1 : a > b ? 1 : 0);
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let s = tokens[0];
        let m = parseInt(tokens[1], 10);
        let dict_words = tokens.slice(2, (2 + m));
        for (const sent of word_break(s, dict_words)) {
            console.log(sent);
        }
    }
}
main();
