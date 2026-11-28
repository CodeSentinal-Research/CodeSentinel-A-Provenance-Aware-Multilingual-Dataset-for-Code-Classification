// Make Sum Divisible by P
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function min_subarray(nums, p) {
    let target = (nums.reduce((a, b) => a + b, 0) % p);
    if (target === 0) {
        return 0;
    }
    let seen = {[0]: -(1)};
    let cur = 0;
    let min_len = (nums.length !== undefined ? nums.length : nums.size);
    for (const [i, x] of [...nums].map((v, i) => [i, v])) {
        cur = ((cur + x) % p);
        let needed = (((cur - target) + p) % p);
        if (_in(needed, seen)) {
            min_len = Math.min(min_len, (i - seen[needed]));
        }
        seen[cur] = i;
    }
    return (min_len < (nums.length !== undefined ? nums.length : nums.size) ? min_len : -(1));
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let nums = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let p = parseInt(tokens[(1 + n)], 10);
        console.log(min_subarray(nums, p));
    }
}
main();
