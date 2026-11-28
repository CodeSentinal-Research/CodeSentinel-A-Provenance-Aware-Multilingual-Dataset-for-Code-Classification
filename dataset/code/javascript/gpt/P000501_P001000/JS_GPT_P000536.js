// Jump Game VI
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
        let dp = ([0] * n);
        dp[0] = nums[0];
        let q = deque([0]);
        for (const i of Array.from({length: (n) - (1)}, (_, i) => (1) + i)) {
            while ((q && q[0] < (i - k))) {
                q.popleft();
            }
            dp[i] = (nums[i] + dp[q[0]]);
            while ((q && dp[q[-(1)]] <= dp[i])) {
                q.pop();
            }
            q.push(i);
        }
        console.log(dp[-(1)]);
    }
}
main();
