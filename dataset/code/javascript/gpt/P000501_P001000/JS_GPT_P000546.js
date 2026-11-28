// Jump Game VII
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let s = tokens[0];
        let min_jump = parseInt(tokens[1], 10);
        let max_jump = parseInt(tokens[2], 10);
        let n = (s.length !== undefined ? s.length : s.size);
        if (s[-(1)] !== "0") {
            console.log("false");
            return;
        }
        let dp = ([false] * n);
        dp[0] = true;
        let reach = 0;
        for (const i of Array.from({length: n}, (_, i) => i)) {
            if (!(dp[i])) {
                continue;
            }
            let start = Math.max((i + min_jump), (reach + 1));
            let end = Math.min((i + max_jump), (n - 1));
            for (const j of Array.from({length: ((end + 1)) - (start)}, (_, i) => (start) + i)) {
                if (s[j] === "0") {
                    dp[j] = true;
                }
            }
            reach = Math.max(reach, end);
        }
        console.log((dp[-(1)] ? "true" : "false"));
    }
}
main();
