// Longest Subarray with Sum K
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let k = parseInt(tokens[(1 + n)], 10);
        let seen = {[0]: -(1)};
        let cur = 0;
        let max_len = 0;
        for (const i of Array.from({length: n}, (_, i) => i)) {
            cur += nums[i];
            if (_in((cur - k), seen)) {
                max_len = Math.max(max_len, (i - seen[(cur - k)]));
            }
            if (!_in(cur, seen)) {
                seen[cur] = i;
            }
        }
        console.log(max_len);
    }
}
main();
