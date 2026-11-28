// N-Queens
const fs = require("fs");
function _in(item, container) { if (Array.isArray(container) || typeof container === "string") return container.includes(item); if (container instanceof Set || container instanceof Map) return container.has(item); if (typeof container === "object" && container !== null) return item in container; return false; }
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function solve_n_queens(n) {
    let [cols, diag1, diag2] = [new Set(), new Set(), new Set()];
    let board = [...Array.from({length: n}, (_, i) => i)].map(_ => (["."] * n));
    let res = [];
    function backtrack(r) {
        if (r === n) {
            res.push([...board].map(row => row.join("")));
            return;
        }
        for (const c of Array.from({length: n}, (_, i) => i)) {
            if ((_in(c, cols) || _in((r + c), diag1) || _in((r - c), diag2))) {
                continue;
            }
            cols.add(c);
            diag1.add((r + c));
            diag2.add((r - c));
            board[r][c] = "Q";
            backtrack((r + 1));
            board[r][c] = ".";
            (idx => idx !== -1 && cols.splice(idx, 1))(cols.indexOf(c));
            (idx => idx !== -1 && diag1.splice(idx, 1))(diag1.indexOf((r + c)));
            (idx => idx !== -1 && diag2.splice(idx, 1))(diag2.indexOf((r - c)));
        }
    }
    backtrack(0);
    return res;
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let boards = solve_n_queens(n);
        for (const b of boards) {
            for (const row of b) {
                console.log(row);
            }
            console.log();
        }
    }
}
main();
