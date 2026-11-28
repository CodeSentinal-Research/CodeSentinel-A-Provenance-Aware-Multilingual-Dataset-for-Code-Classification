// Sliding Window Maximum
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
        let q = deque();
        let ans = [];
        for (const [i, x] of [...nums].map((v, i) => [i, v])) {
            while ((q && q[0] < ((i - k) + 1))) {
                q.popleft();
            }
            while ((q && nums[q[-(1)]] <= x)) {
                q.pop();
            }
            q.push(i);
            if (i >= (k - 1)) {
                ans.push(nums[q[0]]);
            }
        }
        console.log(...ans);
    }
}
main();
