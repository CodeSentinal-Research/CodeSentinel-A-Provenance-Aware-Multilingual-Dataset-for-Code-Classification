// Crossword Puzzle Solver
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
function solve_crossword(grid, words) {
    let n = (grid.length !== undefined ? grid.length : grid.size);
    function can_place_h(r, c, w) {
        if ((c + (w.length !== undefined ? w.length : w.size)) > n) {
            return false;
        }
        for (const i of Array.from({length: (w.length !== undefined ? w.length : w.size)}, (_, i) => i)) {
            if ((grid[r][(c + i)] !== "-" && grid[r][(c + i)] !== w[i])) {
                return false;
            }
        }
        return true;
    }
    function place_h(r, c, w) {
        let placed = [];
        for (const i of Array.from({length: (w.length !== undefined ? w.length : w.size)}, (_, i) => i)) {
            if (grid[r][(c + i)] === "-") {
                grid[r][(c + i)] = w[i];
                placed.push([r, (c + i)]);
            }
        }
        return placed;
    }
    function can_place_v(r, c, w) {
        if ((r + (w.length !== undefined ? w.length : w.size)) > n) {
            return false;
        }
        for (const i of Array.from({length: (w.length !== undefined ? w.length : w.size)}, (_, i) => i)) {
            if ((grid[(r + i)][c] !== "-" && grid[(r + i)][c] !== w[i])) {
                return false;
            }
        }
        return true;
    }
    function place_v(r, c, w) {
        let placed = [];
        for (const i of Array.from({length: (w.length !== undefined ? w.length : w.size)}, (_, i) => i)) {
            if (grid[(r + i)][c] === "-") {
                grid[(r + i)][c] = w[i];
                placed.push([(r + i), c]);
            }
        }
        return placed;
    }
    function unplace(placed) {
        for (const [r, c] of placed) {
            grid[r][c] = "-";
        }
    }
    function backtrack(idx) {
        if (idx === (words.length !== undefined ? words.length : words.size)) {
            return true;
        }
        let w = words[idx];
        for (const r of Array.from({length: n}, (_, i) => i)) {
            for (const c of Array.from({length: n}, (_, i) => i)) {
                if (can_place_h(r, c, w)) {
                    let placed = place_h(r, c, w);
                    if (backtrack((idx + 1))) {
                        return true;
                    }
                    unplace(placed);
                }
                if (can_place_v(r, c, w)) {
                    placed = place_v(r, c, w);
                    if (backtrack((idx + 1))) {
                        return true;
                    }
                    unplace(placed);
                }
            }
        }
        return false;
    }
    backtrack(0);
    return grid;
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let grid = [...Array.from({length: n}, (_, i) => i)].map(i => Array.from(tokens[(1 + i)]));
        let w_cnt = parseInt(tokens[(1 + n)], 10);
        let words = tokens.slice((2 + n), ((2 + n) + w_cnt));
        let solved = solve_crossword(grid, words);
        for (const row of solved) {
            console.log(row.join(""));
        }
    }
}
main();
