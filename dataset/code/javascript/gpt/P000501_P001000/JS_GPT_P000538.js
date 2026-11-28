// Shortest Subarray with Sum at Least K
const fs = require("fs");
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
        let prefix = ([0] * (n + 1));
        for (const i of Array.from({length: n}, (_, i) => i)) {
            prefix[(i + 1)] = (prefix[i] + nums[i]);
        }
        let q = deque();
        let min_len = (n + 1);
        for (const i of Array.from({length: (n + 1)}, (_, i) => i)) {
            while ((q && (prefix[i] - prefix[q[0]]) >= k)) {
                min_len = Math.min(min_len, (i - q.popleft()));
            }
            while ((q && prefix[q[-(1)]] >= prefix[i])) {
                q.pop();
            }
            q.push(i);
        }
        console.log((min_len <= n ? min_len : -(1)));
    }
}
main();
