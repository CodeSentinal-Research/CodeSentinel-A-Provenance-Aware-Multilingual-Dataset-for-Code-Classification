// Number of Atoms
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function countOfAtoms(formula) {
    let stack = [defaultdict(Number)];
    let i = 0;
    let n = (formula.length !== undefined ? formula.length : formula.size);
    while (i < n) {
        if (formula[i] === "(") {
            stack.push(defaultdict(Number));
            i += 1;
        } else {
            if (formula[i] === ")") {
                i += 1;
                let i_start = i;
                while ((i < n && /^\d+$/.test(formula[i]))) {
                    i += 1;
                }
                let mult = parseInt((formula.slice(i_start, i) || 1), 10);
                let top = stack.pop();
                for (const [atom, cnt] of Object.entries(top)) {
                    stack[-(1)][atom] += (cnt * mult);
                }
            } else {
                i_start = i;
                i += 1;
                while ((i < n && formula[i].islower())) {
                    i += 1;
                }
                let atom = formula.slice(i_start, i);
                i_start = i;
                while ((i < n && /^\d+$/.test(formula[i]))) {
                    i += 1;
                }
                let cnt = parseInt((formula.slice(i_start, i) || 1), 10);
                stack[-(1)][atom] += cnt;
            }
        }
    }
    let counts = stack[0];
    return [...[...counts].sort((a, b) => a < b ? -1 : a > b ? 1 : 0)].map(atom => (atom + (counts[atom] > 1 ? String(counts[atom]) : ""))).join("");
}
function main() {
    let s = _stdin_all.trim();
    if (s) {
        console.log(countOfAtoms(s));
    }
}
main();
