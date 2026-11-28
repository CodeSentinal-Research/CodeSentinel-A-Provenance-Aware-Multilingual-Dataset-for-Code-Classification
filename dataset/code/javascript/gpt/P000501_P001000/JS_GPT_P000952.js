// Count Coprime Numbers in Range
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_lines = _stdin_all.split(/\r?\n/);
let _stdin_line_idx = 0;
function _stdin_next_line() { return _stdin_line_idx < _stdin_lines.length ? _stdin_lines[_stdin_line_idx++] : ""; }
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function count_coprime(n, r) {
    let primes = [];
    let temp = n;
    let d = 2;
    while ((d * d) <= temp) {
        if ((temp % d) === 0) {
            primes.push(d);
            while ((temp % d) === 0) {
                temp = Math.floor(temp / (d));
            }
        }
        d += 1;
    }
    if (temp > 1) {
        primes.push(temp);
    }
    let m = (primes.length !== undefined ? primes.length : primes.size);
    let divisible_count = 0;
    for (const mask of Array.from({length: ((1 << m)) - (1)}, (_, i) => (1) + i)) {
        let prod = 1;
        let bits = 0;
        for (const i of Array.from({length: m}, (_, i) => i)) {
            if (((mask >> i) & 1)) {
                prod *= primes[i];
                bits += 1;
            }
        }
        if ((bits % 2) === 1) {
            divisible_count += Math.floor(r / prod);
        } else {
            divisible_count -= Math.floor(r / prod);
        }
    }
    return (r - divisible_count);
}
let [n, r] = _stdin_next_line().trim().split(/\s+/).map(Number);
console.log(count_coprime(n, r));
