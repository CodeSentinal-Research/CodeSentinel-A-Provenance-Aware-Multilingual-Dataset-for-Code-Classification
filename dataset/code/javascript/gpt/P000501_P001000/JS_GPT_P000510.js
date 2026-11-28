// Final Prices With a Special Discount in a Shop
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let prices = Array.from(tokens.slice(1, (1 + n)).map(Number));
        let ans = Array.from(prices);
        let stack = [];
        for (const [i, p] of [...prices].map((v, i) => [i, v])) {
            while ((stack && prices[stack[-(1)]] >= p)) {
                let prev = stack.pop();
                ans[prev] -= p;
            }
            stack.push(i);
        }
        console.log(...ans);
    }
}
main();
